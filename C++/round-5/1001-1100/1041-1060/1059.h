class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        if (!graph[destination].empty()) {
            return false;
        }
        
        vector<int> seen(n, -1);
        return dfs(graph, source, destination, seen);
    }
    
private:
    bool dfs(const vector<vector<int>> &graph, int source, int destination, vector<int> &seen) {
        if (seen[source] >= 0) {
            return (seen[source] == 1);
        }
        if (graph[source].empty()) {
            seen[source] = (source == destination);
            return seen[source];
        }
        
        // Temporarily block the node.
        seen[source] = 0;
        for (int next : graph[source]) {
            if (!dfs(graph, next, destination, seen)) {
                return false;
            }
        }
        seen[source] = 1;
        return true;
    }
};