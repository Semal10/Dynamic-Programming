#include <bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

string a,b,str;
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

//BOTTOM-UP
lld longestCommonSubstringDynamic(lld n1,lld n2){
    lld ans=0;
    lld i,j,s,e;
    
    for(i=0;i<=n1+1;i++){
        for(j=0;j<=n2+1;j++){
            if(i==0 || j==0) dp1[i][j]=0;
            else if(a[i-1]==b[j-1]){
                dp1[i][j]=dp1[i-1][j-1]+1;
                if(dp1[i][j]>ans){
                    ans=dp1[i][j];
                    s=i;
                    e=j;
                }
            }
            else{
                dp1[i][j]=0;
            }
        }
    }
    
    lld temp=ans;
    i=s;
    j=e;
    while(temp>0){
        if(dp1[i][j]==temp){
            str+=a[i-1];
            i--;
            j--;
            temp--;
        }
    }
    
    
    return ans;
}

int main() {
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	cout<<longestCommonSubstringDynamic(a.length()-1,b.length()-1)<<endl;
	reverse(str.begin(),str.end());
	cout<<str<<endl;
}
