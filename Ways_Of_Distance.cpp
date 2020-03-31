#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define INF INT_MAX
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld n,dp[100001],dp1[100001];

//TOP-DOWN
lld distanceWays(lld n){
    lld c=0;
    if(n==0) return dp[n]=1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    c=distanceWays(n-1)+distanceWays(n-2)+distanceWays(n-3);
    return dp[n]=c;
}

//BOTTOM-UP
lld distanceWaysDynamic(lld n){
    dp1[0]=dp1[1]=1;
    dp1[2]=2;
    for(lld i=3;i<=n;i++){
        dp1[i]=dp1[i-1]+dp1[i-2]+dp1[i-3];
    }
    return dp1[n];
}

int main() {
	lld i,j;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<distanceWaysDynamic(n)<<endl;
}
