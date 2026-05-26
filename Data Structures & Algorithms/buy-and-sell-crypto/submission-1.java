class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int pri = Integer.MAX_VALUE;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (prices[i] < pri) {
                pri = prices[i];
            } else {
                int profit = prices[i] - pri;
                ans = Math.max(ans, profit);
            }
        }

        return ans;
    }
}