int minimumCoinChange(int amt,int coins[],int n){
    int dp[amt+1];
    int numbretrieve[amt+1];
    set<int> s;
    int i,j;
    // BASE CASE For Making 0 Amount You Need Zero Coins
    dp[0]=0;
    for(i=1;i<=amt;i++){
        dp[i]=INT_MAX;
    }
    for(i=0;i<=amt;i++){
        numbretrieve[i]=-1;
    }
    for(i=0;i<n;i++){
        for(j=1;j<=amt;j++){
            if(coins[i]<=j){
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
                numbretrieve[j]=i;
            }
        }
    }
    int answer=dp[amt];
    while(amt!=0){
        s.insert(coins[numbretrieve[amt]]);
        amt-=coins[numbretrieve[amt]];
    }
    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    return answer;
}

int main(){
fast;
cin.tie(0);
int coins[4]={1,5,6,8};
int amt=14;
// Minimum Coin Required To Change To amt is
cout<<minimumCoinChange(amt,coins,4)<<endl;

}
