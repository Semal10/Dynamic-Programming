#include<bits/stdc++.h>
#include<climits>
 
using namespace std;
 
#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
typedef long long int lld; 
 
lld n,a[100001],dp[100001];
 
//TOP-DOWN
lld frogOne(lld n){
    lld c=INT_MAX;
    if(n==2) return dp[n]=min(abs(a[n]-a[0]),abs(a[n]-a[1])+abs(a[1]-a[0]));
    if(n==1) return dp[n]=abs(a[n]-a[0]);
    if(n==0) return dp[n]=0;
    if(dp[n]!=-1) return dp[n];  
    c=min(frogOne(n-1)+abs(a[n-1]-a[n]),frogOne(n-2)+abs(a[n-2]-a[n]));
    return dp[n]=c;
}
 
 
int main(){
    fast;
    cin.tie(0);
    lld i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<frogOne(n-1)<<endl;
}
