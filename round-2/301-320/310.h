class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> neighbors(n);
        vector<int> neighbor_counts(n, 0);

        for (auto edge : edges) {
            neighbors[edge.first].push_back(edge.second);
            ++neighbor_counts[edge.first];
            neighbors[edge.second].push_back(edge.first);
            ++neighbor_counts[edge.second];
        }

        queue<int> leaves;
        unordered_set<int> visited;
        for (int i = 0; i < n; ++i)
            if (neighbor_counts[i] <= 1) {
                leaves.push(i);
                visited.insert(i);
            }

        // iteratively throw leaves in the contour
        while (n > 2) {
            n -= leaves.size();
            for (int len = leaves.size(); len > 0; --len) {
                int curr = leaves.front();
                leaves.pop();
            for (auto nb : neighbors[curr])
                    if (--neighbor_counts[nb] <= 1 && visited.find(nb) == visited.end()) {
                        leaves.push(nb);
                        visited.insert(nb);
                    }
            }
        }
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};