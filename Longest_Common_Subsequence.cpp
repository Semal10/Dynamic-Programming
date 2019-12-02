#include<bits/stdc++.h>
using namespace std;

int main(){
fast;
cin.tie(0);
string s1="abcdaf";
string s2="acbcf";
//vector<vector<int>> dp(s1.length()+1,s2.length()+1);
int dp[s1.length()+1][s2.length()+1];
int i,j,maximum=0;
string ans="";
bool flag,f;
// Initializing 0th Row && 0th Column As 0 
for(i=0;i<s1.length()+1;i++){
    dp[i][0]=0;
}
for(i=0;i<s2.length()+1;i++){
    dp[0][i]=0;
}
// Matrix Iteration Logic
// flag & f is used to keep track for which alphabets
// are responsible for LCS (Diagonal Traversal)
for(i=1;i<s1.length()+1;i++){
    flag=false;
    f=false;
    for(j=1;j<s2.length()+1;j++){
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
            flag=true;
        }
        else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        if(dp[i][j]>maximum){
            maximum=dp[i][j];
            f=true;
        }
    }
    if(flag && f){
        ans+=s1[i-1];
    }
}
// Longest Common Subsequence Length
cout<<maximum<<endl;
// Longest Common Subsequence String
cout<<ans<<endl;
}
