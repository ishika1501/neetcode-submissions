class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        List<Integer> pre = new ArrayList<>();
        List<Integer> suf = new ArrayList<>();
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            pre.add(1);
            suf.add(1);
        }

        for (int i = 1; i < n; i++){
            pre.set(i, pre.get(i-1)* nums[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            suf.set(i, suf.get(i+1)*nums[i+1]);
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] = pre.get(i) * suf.get(i);
        }
        return ans;
    }
}  
