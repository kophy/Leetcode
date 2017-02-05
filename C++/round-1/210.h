class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> adj(numCourses);
        vector<int> indegrees(numCourses, 0);
        vector<int> result;
        for (auto prerequisite : prerequisites) {
            if (adj[prerequisite.second].find(prerequisite.first) == adj[prerequisite.second].end())
                ++indegrees[prerequisite.first];
            adj[prerequisite.second].insert(prerequisite.first);
        }
        while (result.size() < numCourses) {
            int curr = -1;
            for (int i = 0; i < numCourses; i++) {
                if (indegrees[i] == 0) {
                    curr = i;
                    break;
                }
            }
            if (curr == -1) {
                result.clear();
                return result;
            }
            for (auto neighbor : adj[curr])
                --indegrees[neighbor];
            indegrees[curr] = INT_MAX;
            result.push_back(curr);
        }
        return result;
    }
};