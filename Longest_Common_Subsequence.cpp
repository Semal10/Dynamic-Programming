#include <bits/stdc++.h>
#include<climits>
using namespace std;

typedef long long int lld;

string a,b;
string ans;
bool flag,f;
lld dp[1001][1001],dp1[1001][1001],maxx;

//TOP-DOWN
lld lcs(lld n1,lld n2){
    lld c=INT_MIN;
    if(n1<0 || n2<0) return 0;
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    if(a[n1]==b[n2]){
        c=lcs(n1-1,n2-1)+1;
    }
    else{
        c=max(lcs(n1-1,n2),lcs(n1,n2-1));
    }
    if(n1>=0 && n2>=0) dp[n1][n2]=c;
    return c;
}

//BOTTOM-UP
lld lcsDynamic(lld n1 , lld n2){
    for(lld i=1;i<=n1+1;i++){
        flag=false;
        f=false;
        for(lld j=1;j<=n2+1;j++){
            if(a[i]==b[j]){
                dp1[i][j]=dp1[i-1][j-1]+1;
                flag=true;
            }
            else{
                dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1]);
            }
            if(dp1[i][j]>maxx){
                f=true;
                maxx=dp1[i][j];
            }
        }
        if(flag && f) ans+=a[i-1];
    }
    return dp1[n1+1][n2+1];
}


int main() {
	lld i,j;
	cin>>a>>b;
	ans="";
	memset(dp,-1,sizeof(dp));
	memset(dp1,0,sizeof(dp1));
	cout<<lcsDynamic(a.length()-1,b.length()-1)<<endl;
	cout<<ans<<endl;
	
}
