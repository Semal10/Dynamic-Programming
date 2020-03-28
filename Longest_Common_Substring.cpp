#include <bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

string a,b;
lld dp[1001][1001][2];

//TOP-DOWN
lld longestCommonSubstring(lld n1 , lld n2 , bool flag){
    lld c=INT_MIN;
    lld f=0;
    if(flag) f=1;
    if(n1<0 || n2<0) return 0;
    if(dp[n1][n2][f]!=-1) return dp[n1][n2][f];
    if(a[n1]==b[n2]){
        c=max(c,longestCommonSubstring(n1-1,n2-1,true)+1);
    }
    else{
        if(flag){
            c=0;
            flag=false;
        }
        c=max(longestCommonSubstring(n1-1,n2,false),longestCommonSubstring(n1,n2-1,false));
    }
    return dp[n1][n2][f]=c;
}


int main() {
	cin>>a>>b;memset(dp,-1,sizeof(dp));
	cout<<longestCommonSubstring(a.length()-1,b.length()-1,false)<<endl;
}
