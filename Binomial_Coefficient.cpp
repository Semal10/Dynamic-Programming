#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld n,k,dp[1001][1001],dp1[1001][1001];

//TOP-DOWN
lld binomialCoefficient(lld n,lld k){
    if(k==n || k==0) return dp[n][k]=1;
    if(dp[n][k]!=-1) return dp[n][k];
    return dp[n][k]=(binomialCoefficient(n-1,k) + binomialCoefficient(n-1,k-1));
}

//BOTTOM-UP
lld binomialCoefficientDynamic(lld n,lld k){
    lld i,j;
    for(i=0;i<=n;i++){
        dp1[i][n]=1;
        dp1[i][0]=1;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            dp1[i][j]=dp1[i-1][j-1]+dp1[i-1][j];    
        }
    }
    return dp1[n][k];
}

int main(){
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	cout<<binomialCoefficientDynamic(n,k)<<endl;
}
