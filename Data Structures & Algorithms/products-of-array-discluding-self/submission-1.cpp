class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int zeroCount = 0;
        for (auto it : nums) {
            if (it == 0) {
                zeroCount++;
                continue;
            }
            prod *= it;
        }

        vector<int>ans;
        for(int i=0; i<n; i++){
            if(zeroCount>1){
                ans.push_back(0);
            }else if(zeroCount == 1){
                if (nums[i] == 0)
                    ans.push_back(prod);
                else
                    ans.push_back(0);
            }else{
                ans.push_back(prod / nums[i]);
            }
        }

        return ans;
    }
};
