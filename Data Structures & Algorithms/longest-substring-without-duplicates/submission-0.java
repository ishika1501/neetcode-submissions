class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            boolean found = false;
            for (int k = i; k < j; k++) {
                if (s.charAt(k) == s.charAt(j)) {
                    i = k + 1;  
                    found = true;
                    break;
                }
            }

            ans = Math.max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
}