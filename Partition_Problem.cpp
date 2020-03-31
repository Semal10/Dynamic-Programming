#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define INF INT_MAX
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld n,m,a[100001];
lld dp[100001];

//TOP-DOWN
bool partitionProblem(lld n,lld sum1,lld sum2){
    if(sum1==sum2){
        dp[n]=1;
        return true;
    }
    if(n<0 && sum1!=sum2) return false;
    if(dp[n]!=0) return dp[n];
    return dp[n]=partitionProblem(n-1,sum1+a[n],sum2-a[n]) || partitionProblem(n-1,sum1,sum2);
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
	if(partitionProblem(n-1,0,sum)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
