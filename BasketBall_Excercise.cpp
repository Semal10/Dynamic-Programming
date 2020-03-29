#include <bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld n,a[100001],b[100001],dp[100001][3];

lld basketBallExcercise(lld i,lld d){
    lld c=INT_MIN;
    if(i==n) return dp[i][d]=0;
    if(dp[i][d]!=-1) return dp[i][d];
    if(d==0){
        c=max(basketBallExcercise(i+1,1)+a[i],basketBallExcercise(i+1,2)+b[i]);
    }
    else if(d==1){
        c=max(basketBallExcercise(i+1,1),basketBallExcercise(i+1,2)+b[i]);
    }
    else{
        c=max(basketBallExcercise(i+1,2),basketBallExcercise(i+1,1)+a[i]);
    }
    return dp[i][d]=c;
}

int main() {
	cin>>n;
	lld i,j;
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	for(i=0;i<n;i++){
	    cin>>b[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<basketBallExcercise(0,0)<<endl;
}
