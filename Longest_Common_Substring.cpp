#include <bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

string a,b;
lld dp[1001][1001],dp1[1001][1001];

//TOP-DOWN
lld longestCommonSubstring(lld n1 , lld n2 , lld count){
    if(n1<0 || n2<0) return dp[n1][n2]=count;
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    if(a[n1]==b[n2]){
        count=longestCommonSubstring(n1-1,n2-1,count+1);
    }
    count=max(count,max(longestCommonSubstring(n1-1,n2,0),longestCommonSubstring(n1,n2-1,0)));
    return dp[n1][n2]=count;
}

int main() {
	cin>>a>>b;memset(dp,-1,sizeof(dp));
	cout<<longestCommonSubstring(a.length()-1,b.length()-1,0)<<endl;
}
