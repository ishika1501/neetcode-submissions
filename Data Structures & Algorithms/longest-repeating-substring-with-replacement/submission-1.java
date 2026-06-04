
class Solution {
    public int characterReplacement(String s, int k) {
        int left = 0;
        int ans = 0;
        int maxi = 0;
        HashMap<Character, Integer> mp = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
            maxi = Math.max(maxi, mp.get(ch));

            if ((i - left + 1) - maxi > k) {
                char leftch = s.charAt(left);
                mp.put(leftch, mp.get(leftch) - 1);
                left++;
            }

            ans = Math.max(ans, i - left + 1);
        }

        return ans;
    }
}
