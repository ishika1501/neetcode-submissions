class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // int n=numCourses.size();
        vector<int>inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto pre: prerequisites){
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        int count = 0; // Count of courses we can process
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
        
            for (int nextCourse : adj[course]) {
                inDegree[nextCourse]--;  // Remove dependency
                if (inDegree[nextCourse] == 0) q.push(nextCourse);
            }
        }
        
        return count == numCourses;
    }
};
