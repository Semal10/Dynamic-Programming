#include<bits/stdc++.h>
#include<climits>
 
using namespace std;
 
#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
typedef long long int lld; 
 
lld n,k,a[100001],dp[100001];
 
//TOP-DOWN
lld frogTwo(lld n){
    lld c=INT_MAX;
    if(n<=0) return dp[n]=0;
    if(dp[n]!=-1) return dp[n];  
    for(lld i=1;i<=k;i++){
        if(n-i>=0){
            c=min(c,frogTwo(n-i)+abs(a[n]-a[n-i]));
        }
    }
    return dp[n]=c;
}
 
 
int main(){
    fast;
    cin.tie(0);
    lld i,j;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<frogTwo(n-1)<<endl;
}
