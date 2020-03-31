#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define INF INT_MAX
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld a[100001],n,dp[100001];
bool dp1[1001][1001];

//TOP-DOWN
lld partitionSubset(lld n,lld sum1,lld sum2){
    lld c=INT_MAX;
    if(n==0){
        return dp[n]=abs(sum1-sum2);
    }
    if(dp[n]!=-1) return dp[n];
    else{
        c=min(c,min(partitionSubset(n-1,sum1+a[n-1],sum2-a[n-1]),partitionSubset(n-1,sum1,sum2)));
    }
    return dp[n]=c;
}

//BOTTOM-UP
lld partitionSubsetDynamic(lld n,lld sum){
    lld i,j;
    for(i=0;i<=n;i++){
        dp1[i][0]=true;
    }
    for(i=1;i<=sum;i++){
        dp1[0][i]=false;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            dp1[i][j]=dp1[i-1][j];
            if(a[i-1]<=j) dp1[i][j] |= dp1[i-1][j-a[i-1]];
        }
    }
    for(j=sum/2;j>=0;j--){
        if(dp1[n][j]){
            return sum-2*j;
        }
    }
}

int main() {
	lld i,j;
	cin>>n;
	lld sum=0;
	for(i=0;i<n;i++){
	    cin>>a[i];
	    sum+=a[i];
	}
	memset(dp,-1,sizeof(dp));
	//cout<<partitionSubset(n,0,sum)<<endl;
	cout<<partitionSubsetDynamic(n,sum)<<endl;
}
