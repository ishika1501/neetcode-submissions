class Solution {
public:

    string encode(vector<string>& strs) {
        string encode = "";
        for (auto it : strs) {
            int len = it.length();
            encode += to_string(len);
            encode += '#';
            encode += it;
        }

        return encode;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            j++;
            string st = s.substr(j, len);
            ans.push_back(st);
            i = j + len - 1;
        }

        return ans;
    }
};