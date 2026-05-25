class Solution {
public:
    // int func(vector<int>& nums, int idx){
    //     if(idx>nums.size())return 0;

    //     int take=func(nums, idx+2)+nums[idx];
    //     int nottake=func(nums, idx+1);

    //     return max(nottake, take);

    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // return func(nums , 0 );
        if(nums.empty())return 0;
        vector<int>dp(n ,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n-1];
    }
};
