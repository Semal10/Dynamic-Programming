#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld a[100001],n,dp[100001][3],dp1[100001][3];

//TOP-DOWN
lld vacation(lld n,lld comp){
    lld c=INT_MAX;
    if(n<0) return 0;
    if(dp[n][comp]!=-1) return dp[n][comp];
    if(a[n]==0){
        c=min(c,vacation(n-1,0)+1);
    }
    else if(comp==0){
        if(a[n]==1){
            c=min(c,vacation(n-1,1));
        }
        else if(a[n]==2){
            c=min(c,vacation(n-1,2));
        }
        else{
            c=min(c,min(vacation(n-1,1),vacation(n-1,2)));
        }
    }
    else if(comp==1){
        if(a[n]==2 || a[n]==3){
            c=min(c,vacation(n-1,2));
        }
        else{
            c=min(c,vacation(n-1,0)+1);
        }
    }
    else{
        if(a[n]==1 || a[n]==3){
            c=min(c,vacation(n-1,1));
        }
        else{
            c=min(c,vacation(n-1,0)+1);
        }
    }
    return dp[n][comp]=c;
}

//BOTTOM-UP
lld vacationDynamic(lld n){
    lld i,j;
    for(i=1;i<=n;i++){
        for(j=0;j<3;j++){
            if(a[i-1]==0){
                dp1[i][j]=dp1[i-1][0]+1;
            }
            else if(j==0){
                if(a[i-1]==1){
                    dp1[i][j]=dp1[i-1][1];
                }
                else if(a[i-1]==2){
                    dp1[i][j]=dp1[i-1][2];
                }
                else{
                    dp1[i][j]=min(dp1[i-1][1],dp1[i-1][2]);
                }
            }
            else if(j==1){
                if(a[i-1]==2 || a[i-1]==3){
                    dp1[i][j]=dp1[i-1][2];
                }
                else{
                    dp1[i][j]=dp1[i-1][0]+1;
                }
            }
            else{
                if(a[i-1]==1 || a[i-1]==3){
                    dp1[i][j]=dp1[i-1][1];
                }
                else{
                    dp1[i][j]=dp1[i-1][0]+1;
                }
            }
        }
    }
    return dp1[n][0];
}

int main() {
	lld i;
	cin>>n;
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	memset(dp1,0,sizeof(dp1));
	//cout<<vacation(n-1,0)<<endl;
    cout<<vacationDynamic(n)<<endl;
}
