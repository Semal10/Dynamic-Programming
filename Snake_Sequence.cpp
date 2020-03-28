#include <bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld a[1001][1001],n,m,dp[1001][1001],dp1[1001][1001];
vector<lld> v;

//TOP-DOWN
lld snakeSequence(lld i,lld j){
    lld c=INT_MIN;
    if(i>=n || j>=m) return dp[i][j]=1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i<=n-2 && abs(a[i+1][j]-a[i][j])==1){
        c=max(c,snakeSequence(i+1,j)+1);
    }
    else{
        c=max(c,snakeSequence(i+1,j));
    }
    if(j<=m-2 && abs(a[i][j+1]-a[i][j])==1){
        c=max(c,snakeSequence(i,j+1)+1);
    }
    else{
        c=max(c,snakeSequence(i,j+1));
    }
    return dp[i][j]=c;
}

//BOTTOM-UP
lld snakeSequenceDynamic(lld n,lld m){
    lld ans=INT_MIN;
    lld start,end;
    for(lld i=0;i<n;i++){
        for(lld j=0;j<m;j++){
            dp1[i][j]=1;
        }
    }
    for(lld i=0;i<n;i++){
        for(lld j=0;j<m;j++){
            if(i>0 && abs(a[i-1][j]-a[i][j])==1){
                dp1[i][j]=max(dp1[i][j],dp1[i-1][j]+1);
            }
            if(j>0 && abs(a[i][j-1]-a[i][j])==1){
                dp1[i][j]=max(dp1[i][j],dp1[i][j-1]+1);
            }
        }
    }
    for(lld i=0;i<n;i++){
        for(lld j=0;j<m;j++){
            if(dp1[i][j]>ans){
                ans=dp1[i][j];
                start=i;
                end=j;
            }  
        }
    }
    lld i=start;
    lld j=end;
    lld temp=ans;
    v.emplace_back(a[i][j]);
    while(--ans>0){
        if(dp1[i-1][j]==ans){
            i--;
            v.emplace_back(a[i][j]);
        }
        else if(dp1[i][j-1]==ans){
            j--;
            v.emplace_back(a[i][j]);
        }
    }
    
    return temp;
}


int main() {
	lld i,j;
	cin>>n>>m;
	for(i=0;i<n;i++){
	    for(j=0;j<m;j++){
	        cin>>a[i][j];
	    }
	}
	memset(dp,-1,sizeof(dp));
	//cout<<snakeSequence(0,0)<<endl;
	cout<<snakeSequenceDynamic(n,m)<<endl;
	reverse(v.begin(),v.end());
	for(lld i=0;i<v.size();i++){
	    cout<<v[i]<<" ";
	}
}
