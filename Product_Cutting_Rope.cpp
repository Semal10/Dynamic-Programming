#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define INF INT_MAX
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld n;
lld dp[100001],dp1[100001];

//TOP-DOWN
lld productCuttingRope(lld n){
    lld c=INT_MIN;
    if(n==1) return dp[n]=1;
    if(dp[n]!=-1) return dp[n];
    for(lld i=1;i<n;i++){
        c=max(c,max((i*(n-i)),(productCuttingRope(i)*productCuttingRope(n-i))));
    }
    return dp[n]=c;
}

//BOTTOM-UP
lld productCuttingRopeDynamic(lld n){
    dp1[1]=0;
    for(lld i=1;i<=n;i++){
        lld temp=0;
        for(lld j=1;j<=i/2;j++){
            temp=max(temp,max(j*(i-j),j*dp1[i-j]));
        }
        dp1[i]=temp;
    }
    return dp1[n];
}

int main() {
	lld i,j;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<productCuttingRopeDynamic(n)<<endl;
}
