#include <bits/stdc++.h>
#include<climits>
using namespace std;
typedef long long int lld; 

bool a[1000];
bool dp[1001][1001],dp1[1001][1001];
lld n;

//TOP-DOWN
bool isJumpingBall(lld s,lld p){
    if(s==0 && (p>=0 && p<n)){
        dp1[s][p]=true;
        return dp[s][p]=true;
    }
    if(p<0 || p>=n || a[p]==false){
        dp1[s][p]=true;
        return dp[s][p]=false;
    }
    if(dp1[s][p]) return dp[s][p];
    return isJumpingBall(s,p+s) || isJumpingBall(s-1,p+s-1) || isJumpingBall(s+1,p+s+1);
}

//jumping ball with spikes on runway

int main() {
	lld s,i,j;
	cin>>n>>s;
	memset(dp,false,sizeof(dp));
	memset(dp1,false,sizeof(dp1));
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	if(isJumpingBall(s,0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
