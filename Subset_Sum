#include <bits/stdc++.h>
#include<climits>
using namespace std;

typedef long long int lld; 

lld sum,n,a[1000];
vector<lld> v ;

bool dp[1000][1000];

bool isSubsetSumTopDown(lld i,lld sum){
        if(i==0 && sum!=0){
            dp[i][sum]=false;
            return false;
        }
        if(sum==0){
            dp[i][sum]=true;
            return true;
        }
        if(sum<a[i]){
            //isSubsetSum(i+1,sum);
            return dp[i][sum]=isSubsetSum(i-1,sum);
        }
        else{
            //dp[i][sum] = isSubsetSum(i+1,sum) || isSubsetSum(i+1,sum-a[i]);
            return dp[i][sum]=isSubsetSum(i-1,sum) || isSubsetSum(i-1,sum-a[i]);
        }
}


bool isSubsetSum(lld n,lld sum) 
{ 
    // The value of subset[i][j] will be true if there is a  
    // subset of set[0..j-1] with sum equal to i 
   
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
      dp[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
      dp[0][i] = false; 
   
     // Fill the subset table in botton up manner 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<a[i-1]) 
         dp[i][j] = dp[i-1][j]; 
         if (j >= a[i-1]) 
           dp[i][j] = dp[i-1][j] ||  dp[i - 1][j-a[i-1]]; 
       } 
     } 
   
   
     return dp[n][sum]; 
} 

int main() {
	lld i;
	cin>>n;
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	cin>>sum;
	if(isSubsetSum(n,sum)){
	    cout<<"YES"<<endl;
        i=n;
        lld j=sum;
        vector<lld> v;
        while(true){
            if(i==0) break;
            if(dp[i-1][j]==1) i--;
            else{
                v.push_back(a[i-1]);
                j-=a[i-1];
                i--;
            }
        }
        for(i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
	}
	else cout<<"NO"<<endl;
}
