class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int[]left = new int[n];
        int[]right= new int[n];
        left[0]=height[0];
        for(int i=1; i<n; i++){
            left[i]=Math.max(height[i], left[i-1]);
        }
        right[n-1]=height[n-1];
        for(int j=n-2; j>=0; j--){
           right[j] = Math.max(right[j+1], height[j]);
        }
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += Math.min(left[i], right[i]) - height[i];
        }
        return water;
    }
}
