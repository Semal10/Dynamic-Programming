#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define INF INT_MAX
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld a[1001][1001],b[1001][1001],n,dp[1001][3],dp1[1001][3];

//All Pairs Shortest Path Problem 
//BOTTOM-UP
void shortestPath(lld n){
    lld i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==-1){
                b[i][j]=a[i][j]=INT_MAX;
            }
            else{
                b[i][j]=a[i][j];
            }
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
            }
        }
    }
}


int main() {
	lld i,j;
	cin>>n;
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        cin>>a[i][j];
	    }
	}
	shortestPath(n);
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        cout<<b[i][j]<<" ";
	    }
	    cout<<endl;
	}
}
