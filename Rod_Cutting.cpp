#include <bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long int lld; 

lld a[1000],ans;
lld dp[1001];
lld dp1[1001];

//TOP-DOWN
lld rodCutting(lld n){
    if(n<=0) return dp[n]=0;
    if(dp[n]!=-1) return dp[n];
    ans=INT_MIN;
    for(lld i=0;i<n;i++){
        ans=max(ans,a[i]+rodCutting(n-i-1));
    }
    dp[n]=ans;
    return dp[n];
}

//BOTTOM-UP
lld rodCuttingDynamic(lld n){
    ans=INT_MIN;
    for(lld i=1;i<=n;i++){
        ans=INT_MIN;
        for(lld j=0;j<i;j++){
            ans=max(ans,a[j]+dp1[i-j-1]);
        }
        dp1[i]=ans;
    }
    return dp1[n];
}

int main() {
	lld n,i;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	memset(dp1,0,sizeof(dp1));
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	cout<<rodCuttingDynamic(n)<<endl;
}
