class Solution {
    public boolean hasDuplicate(int[] nums) {
        int n = nums.length;
        java.util.Arrays.sort(nums);

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                return true;
            }
        }
        return false;
    }
}