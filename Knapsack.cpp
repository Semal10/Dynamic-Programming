#include <bits/stdc++.h>
#include<climits>
using namespace std;

#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long int lld;

lld value[1001],weight[1001],capacity,n,dp[1001][1001],dp1[1001][1001];
vector<lld> v;

//TOP-DOWN
lld knapsack(lld n,lld capacity){
    lld ans=INT_MIN;
    if(capacity==0) return dp[n][capacity]=0;
    if(n<0 || capacity<0) return INT_MIN;
    if(dp[n][capacity]!=-1) return dp[n][capacity];
    
    ans=max(knapsack(n-1,capacity-weight[n])+value[n],knapsack(n-1,capacity));
    
    return dp[n][capacity]=ans;
}

//BOTTOM-UP
lld knapsackDynamic(lld n,lld capacity){
    lld val[n+1],w[capacity+1];
    for(lld i=1;i<=n;i++){
        val[i]=value[i-1];
    }
    for(lld i=1;i<=capacity;i++){
        w[i]=weight[i-1];
    }
    for(lld i=0;i<=n;i++){
        dp1[i][0]=0;
    }
    for(lld i=0;i<=capacity;i++){
        dp1[0][i]=0;
    }
    for(lld i=1;i<=n;i++){
        for(lld j=1;j<=capacity;j++){
            if(j>=w[i]){
                dp1[i][j]=max(dp1[i-1][j],dp1[i-1][j-w[i]]+val[i]);
            }
            else{
                dp1[i][j]=dp1[i-1][j];
            }
        }
    }
    
    /*for(lld i=0;i<=n;i++){
        for(lld j=0;j<=capacity;j++){
            cout<<dp1[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    lld i=n;
    lld j=capacity;
    while(true){
        if(dp1[i][j]==dp1[i-1][j]) i--;
        else{
            v.emplace_back(i);
            j-=w[i];
        }
        if(j==0) break;
    }
    return dp1[n][capacity];
}


int main() {
	lld i,j;
	cin>>n;
	for(i=0;i<n;i++){
	    cin>>value[i];
	}
	for(i=0;i<n;i++){
	    cin>>weight[i];
	}
	memset(dp,-1,sizeof(dp));
	cin>>capacity;
	cout<<knapsackDynamic(n,capacity)<<endl;
	for(i=0;i<v.size();i++){
	    cout<<"weight : "<<weight[v[i]-1]<<"  "<<" Value : "<<value[v[i]-1]<<endl;
	}

}
