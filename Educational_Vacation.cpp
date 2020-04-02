#include<bits/stdc++.h>
#include<climits>
 
using namespace std;
 
#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
typedef long long int lld; 
 
lld n,a[100001],b[100001],c[100001],dp[100001][4];
 
//TOP-DOWN
lld educationalVacation(lld n,lld comp){
    lld ans=INT_MIN;
    if(n<0) return 0;
    if(dp[n][comp]!=-1) return dp[n][comp];
    if(comp==0){
        ans=max(ans,max(educationalVacation(n-1,1)+a[n],max(educationalVacation(n-1,2)+b[n],educationalVacation(n-1,3)+c[n])));
    }
    else if(comp==1){
        ans=max(ans,max(educationalVacation(n-1,2)+b[n],educationalVacation(n-1,3)+c[n]));
    }
    else if(comp==2){
        ans=max(ans,max(educationalVacation(n-1,1)+a[n],educationalVacation(n-1,3)+c[n]));
    }
    else{
        ans=max(ans,max(educationalVacation(n-1,1)+a[n],educationalVacation(n-1,2)+b[n]));
    }
    return dp[n][comp]=ans;
}
 
 
int main(){
    fast;
    cin.tie(0);
    lld i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<educationalVacation(n-1,0)<<endl;
}
