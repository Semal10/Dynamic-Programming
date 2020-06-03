class Solution {
public:
    int dp[102][102][102];
    int solve(int i,int ca,int cb,vector<vector<int>>& a){
        int c=INT_MAX;
        if(i==a.size()) return dp[i][ca][cb]=0;
        if(dp[i][ca][cb]!=-1) return dp[i][ca][cb];
        string safe="both";
        if(ca>=a.size()/2) safe="second";
        else if(cb>=a.size()/2) safe="first";
        if(safe=="both") c=min(c,min(solve(i+1,ca+1,cb,a)+a[i][0],solve(i+1,ca,cb+1,a)+a[i][1]));
        else if(safe=="first"){
            c=min(c,solve(i+1,ca+1,cb,a)+a[i][0]);
        }
        else{
            c=min(c,solve(i+1,ca+1,cb,a)+a[i][1]);
        }
        return dp[i][ca][cb]=c;
    }   
    
    int twoCitySchedCost(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,a);
    }
};
