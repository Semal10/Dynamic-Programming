#include <bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld a[1001],n,dp[1001][1001];

//TOP-DOWN
lld lis(lld n,lld maxx){
    lld c=INT_MIN;
    if(n==0) return dp[n][maxx]=0;
    if(dp[n][maxx]!=-1) return dp[n][maxx];
    if(a[n]<maxx){
        c=max(lis(n-1,1000),lis(n-1,a[n])+1);
    }
    else{
        c=lis(n-1,1000);
    }
    return dp[n][maxx]=c;
}


int main() {
	lld i,j;
	cin>>n;
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<lis(n-1,1000)<<endl;
	
}
