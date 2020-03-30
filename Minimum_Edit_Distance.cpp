#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld dp[1001][1001],dp1[1001][1001];
string a,b;

//TOP-DOWN
lld minimumEditDistance(lld n1,lld n2){
    lld c=INT_MAX;
    // if string b is empty then delete all characters from string a (n1+1)
    if(n2<0) return dp[n1+1][0]=n1+1;
    // if string a is empty then insett all characters from string b (n2+1)
    if(n1<0) return dp[0][n2+1]=n2+1;
    if(dp[n1+1][n2+1]!=-1) return dp[n1+1][n2+1];
    if(a[n1]==b[n2]){
        c=min(c,minimumEditDistance(n1-1,n2-1));
    }
    else{
        //delete,update,insert
        lld t=min(minimumEditDistance(n1-1,n2)+1,min(minimumEditDistance(n1-1,n2-1)+1,minimumEditDistance(n1,n2-1)+1));
        c=min(c,t);
    }
    return dp[n1+1][n2+1]=c;
}


//BOTTOM-UP
lld minimumEditDistanceDynamic(lld n1,lld n2){
    lld i,j;
    for(i=0;i<=n1;i++){
        for(j=0;j<=n2;j++){
            if(i==0) dp1[i][j]=j;
            
            else if(j==0) dp1[i][j]=i;
            
            else if(a[i-1]==b[j-1]){
                dp1[i][j]=dp1[i-1][j-1];
            }
            else{
                dp1[i][j]=min(dp1[i-1][j],min(dp1[i-1][j-1],dp1[i][j-1]))+1;
            }
        }
    }
    return  dp1[n1][n2];
}


int main(){
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	//cout<<min((lld)b.length(),minimumEditDistance(a.length()-1,b.length()-1))<<endl;
    cout<<minimumEditDistanceDynamic(a.length(),b.length())<<endl;
}
