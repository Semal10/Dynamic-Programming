#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define INF INT_MAX
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld n,m,a[100001],dp[100001],dp1[100001];

//TOP-DOWN
lld gameOptimalStrategy(lld i,lld j){
    lld c=0;
    if(i>j) return 0;
    c=max(a[i]+min(gameOptimalStrategy(i+2,j),gameOptimalStrategy(i+1,j-1)),a[j]+min(gameOptimalStrategy(i,j-2),gameOptimalStrategy(i+1,j-1)));

    return c;
}


int main() {
	lld i,j;
	cin>>n;
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	cout<<gameOptimalStrategy(0,n-1)<<endl;
}
