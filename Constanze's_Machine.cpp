#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

string a;
lld dp[1000001],dp1[1000001],MOD=1000000007;
bool flag;

//TOP-DOWN
lld machine(lld n){
    watch(n);
    watch(a[n]);
    watch(dp[n]);
    lld c=0;
    if(n>=0 && (a[n]=='m' || a[n]=='w')){
        flag=false;
        return dp[n]=0;
    }
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];
    if(n>=1 && a[n]==a[n-1] && (a[n]=='u' || a[n]=='n')){
        c=max(c,((machine(n-2)+1)+machine(n-1))%MOD);
    }
    else c=max(c,machine(n-1));
    return dp[n]=c;
    
}

//BOTTOM-UP
lld machineDynamic(lld n){
    for(auto i : a) if(i=='m' || i=='w') return 0;
    dp1[0] = dp1[1] = 1;
    for(lld i=2;i<=n;++i){
        if(a[i-1]==a[i-2] &&(a[i-1]=='u' || a[i-1]=='n'))
            dp1[i] = (dp1[i-1] + dp1[i-2])%MOD  ;
        else dp1[i] = dp1[i-1] ;
    }
    return dp1[n];
}

int main() {
	cin>>a;
	flag=true;
	memset(dp,-1,sizeof(dp));
	cout<<(machineDynamic(a.length()))%MOD<<endl;
}
