class Solution {
public:
    void func(vector<int>& nums, int target , vector<int>& current, vector<vector<int>>& ans, int idx){
        if(target==0){
            ans.push_back(current);
            return;
        }
        if(target < 0) return;
        for(int i=idx; i<nums.size(); i++){
            current.push_back(nums[i]);
            func(nums, target-nums[i], current , ans, i);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>current;
        func(nums, target, current,ans, 0);
        return ans;
    }
};
