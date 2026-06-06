class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int> need(128, 0);
        for(char c : t)need[c]++;
        int required = m;
        int ans=INT_MAX, left=0;
        int start=0;
        for(int right=0; right<n; right++){
            char c = s[right];
            if(need[c] > 0)required--;

            need[c]--;

            while(required==0){
                if(right - left + 1 < ans){
                    ans = right - left + 1;
                    start = left;
                }

                char ch = s[left];
                need[ch]++;

                if (need[ch] > 0)required++;

                left++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};
