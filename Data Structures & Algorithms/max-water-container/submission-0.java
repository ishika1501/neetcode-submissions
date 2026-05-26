class Solution {
    public int maxArea(int[] heights) {
        int n = heights.length;
        int i = 0, j = n - 1;
        int ans = 0;

        while (i < j) {
            int h = Math.min(heights[i], heights[j]);
            int w = j - i;
            ans = Math.max(ans, h * w);

            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
}