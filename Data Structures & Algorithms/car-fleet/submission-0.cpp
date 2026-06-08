class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> p;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            p.push_back({position[i], time});
        }

        sort(p.rbegin(), p.rend());

        double lastTime = 0;
        int ans = 0;

        for (auto it : p) {
            if (it.second > lastTime) {
                ans++;
                lastTime = it.second;
            }
        }

        return ans;
    }
};