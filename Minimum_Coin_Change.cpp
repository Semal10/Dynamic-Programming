#include <bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld a[1001],value,n,dp[1001][1001],dp1[1001];

//TOP-DOWN
lld minimumCoinChange(lld n,lld value){
    lld c=INT_MAX;
    if(value==0) return dp[n][value]=0;
    if(n<0  || value<0) return INT_MAX;
    if(dp[n][value]!=-1) return dp[n][value];
    
    if(n>=1 && value>=a[n-1])
    c=min(minimumCoinChange(n-1,value),minimumCoinChange(n,value-a[n-1])+1);
    
    return dp[n][value]=c;
}

//TOP-DOWN (For Loop)
lld minimumCoinChangeLoop(lld n,lld value){
    if(value<0 || n<0) return INT_MAX;
    if(value==0) return dp[n][value]=0;
    if(dp[n][value]!=-1) return dp[n][value];
    
    lld ans=INT_MAX;
    for(lld i=0;i<n;i++){
        if(a[i]<=value){
            lld curr=minimumCoinChangeLoop(n,value-a[i])+1;
        
            ans=min(ans,curr);
        }
    }
    return dp[n][value]=ans;
}

//BOTTOM-UP
lld minimumCoinChangeDynamic(lld n,lld value){
    dp1[0]=0;
    for(lld i=1;i<=value;i++){
        dp1[i]=INT_MAX;
    }
    for(lld i=0;i<n;i++){
        for(lld j=1;j<=value;j++){
            if(j>=a[i]){
               dp1[j]=min(dp1[j],dp1[j-a[i]]+1); 
            }
        }
    }
    
    return dp1[value];
}


int main() {
	lld i,j;
	cin>>n;
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	cin>>value;
	cout<<minimumCoinChangeDynamic(n,value)<<endl;

}
