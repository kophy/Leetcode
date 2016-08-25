class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> roots;
        if(n == 1) {
            roots.push_back(0);
            return roots;
        }

        vector<vector<int>> graph(n);
        vector<int> inDegree(n);
		for(auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
            ++inDegree[e.first];
            ++inDegree[e.second];
        }

        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(inDegree[i] == 1)
                q.push(i);

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                int node = q.front();
                inDegree[node] = 0;
                q.pop();

                if(n <= 2)
                    roots.push_back(node);
		for(int &neighbor : graph[node]) {
                    --inDegree[neighbor];
                    if(inDegree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
            n -= size;
        }
        return roots;
    }
};