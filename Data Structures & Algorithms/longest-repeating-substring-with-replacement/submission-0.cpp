class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0;
        int maxi = 0;
        int ans=0;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            maxi = max(maxi, mp[s[i]]);

            if ((i - left + 1) - maxi > k) {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
