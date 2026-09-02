class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }

        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        // for(auto it: mp){
        //     int val = it.first;
        //     int freq = it.second;
        //     pq.push({freq, val});
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }
        // vector<int>result;
        // while(!pq.empty()){
        //     result.push_back(pq.top().second);
        //     pq.pop();
        // }

        // return result;
        vector<vector<int>>freq(n+1);
        vector<int>ans;
        for(auto it: mp){
            int val=it.first;
            int f=it.second;

            freq[f].push_back(val);
        }

        for(int i=n; i>=0; i--){
            if(freq[i].size()<0)continue;
            while(freq[i].size()>0 && k>0){
                ans.push_back(freq[i].back());
                freq[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};
