class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string alphabetically
            anagramGroups[sortedStr].push_back(str); // Group by sorted string
        }
        
        vector<vector<string>> result;
        for (const auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;

    }
};
