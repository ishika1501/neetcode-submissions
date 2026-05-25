class Solution {
public:
    // int func(int n, int idx){
    //     if(idx==n)return 1;
    //     if(idx>n)return 0;
    //     int take=func(n, idx+1 );
    //     int nottake=func(n, idx+2);
    //     return take+nottake;
    // }
    int climbStairs(int n) {
        // return func(n ,0);
        vector<int>dp(n+1, 0);
        dp[1] = 1; 
        dp[2] = 2;
        for(int i=3; i<n+1; i++){
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
};
