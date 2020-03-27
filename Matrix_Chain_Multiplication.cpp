#include <bits/stdc++.h>
#include<climits>
using namespace std;

typedef long long int lld;

lld a[1001],dp[1001][1001],dp1[1001][1001];

//TOP-DOWN
lld matrixMuliplication(lld i,lld j){
    if(i==j) return dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];
    lld c=INT_MAX;
    
    for(lld k=i;k<j;k++){
        c=min(c,matrixMuliplication(i,k) + matrixMuliplication(k+1,j) + a[i-1]*a[k]*a[j]);
    }
    return dp[i][j]=c;
}

// BOTTOM-UP
lld matrixMuliplicationDynamic(lld n){
    lld c=INT_MAX;
    for(lld i=1;i<n;i++){
        dp1[i][i]=0;
    }
    for(lld l=2;l<n;l++){
        for(lld i=1;i<n-l+1;i++){
            c=INT_MAX;
            lld j=i+l-1;
            for(lld k=i;k<j;k++){
                c=min(c,dp1[i][k]+dp1[k+1][j]+a[i-1]*a[k]*a[j]);
            }
            dp1[i][j]=c;
        }
    }
    return dp1[1][n-1];
}


int main() {
	lld i,n;
	cin>>n;
	for(i=0;i<=n;i++){
	    cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	memset(dp1,0,sizeof(dp1));
	//cout<<matrixMuliplication(1,n)<<endl;
    cout<<matrixMuliplicationDynamic(n+1)<<endl;
}
