#include<bits/stdc++.h>
#include<climits>
 
using namespace std;
 
#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
typedef long long int lld; 
 
string a,b,s=""; 
lld dp[1001][1001],dp1[1001][1001]; 
 
//TOP-DOWN
lld shortestCommonSupersequence(lld i,lld j){
    lld c=INT_MAX;
    if(i>=a.length()) return dp[i][j]=max(0ll,(lld)b.length()-j);
    if(j>=b.length()) return dp[i][j]=max(0ll,(lld)a.length()-i);
    if(dp[i][j]!=-1) return dp[i][j]; 
    if(a[i]==b[j]){
        c=min(c,shortestCommonSupersequence(i+1,j+1)+1);
    }
    else{
        c=min(c,min(shortestCommonSupersequence(i+1,j)+1,shortestCommonSupersequence(i,j+1)+1));
    }
    return dp[i][j]=c;
}

//BOTTOM-UP
lld shortestCommonSupersequenceDynamic(lld n1,lld n2){
    lld i,j;
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            if(i==0){
                dp1[i][j]=j+1;
            }
            else if(j==0){
                dp1[i][j]=i+1;
            }
            else{
                if(a[i]==b[j]){
                    dp1[i][j]=dp1[i-1][j-1]+1;
                }
                else{
                    dp1[i][j]=min(dp1[i-1][j]+1,dp1[i][j-1]+1);
                }
            }
        }
    }   
    lld index=dp1[n1-1][n2-1];
    i = a.length(), j = b.length(); 
    while (i > 0 && j > 0){ 
        // If current character in X and Y are same, then 
        // current character is part of shortest supersequence 
        if (a[i - 1] == b[j - 1]){ 
            // Put current character in result 
            s.push_back(a[i - 1]); 
            // reduce values of i, j and index 
            i--, j--, index--; 
        } 
        // If current character in X and Y are different 
        else if (dp1[i - 1][j] > dp1[i][j - 1]){ 
            // Put current character of Y in result 
            s.push_back(b[j - 1]); 
            // reduce values of j and index 
            j--, index--; 
        } 
        else{ 
            // Put current character of X in result 
            s.push_back(a[i - 1]); 
            // reduce values of i and index 
            i--, index--; 
        } 
    } 
  
    // If Y reaches its end, put remaining characters 
    // of X in the result string 
    while (i > 0){ 
        s.push_back(a[i - 1]); 
        i--, index--; 
    } 
    // If X reaches its end, put remaining characters 
    // of Y in the result string 
    while (j > 0){ 
        s.push_back(b[j - 1]); 
        j--, index--; 
    } 
  
    // reverse the string and return it 
    reverse(s.begin(), s.end()); 
    
    return dp1[n1-1][n2-1];
}
 
 
int main(){
fast;
cin.tie(0);
cin>>a>>b;
memset(dp,-1,sizeof(dp));
//cout<<shortestCommonSupersequence(0,0)<<endl;
cout<<shortestCommonSupersequenceDynamic(a.length(),b.length())<<endl;
cout<<s<<endl;
}
