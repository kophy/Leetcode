class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        m[nullptr] = nullptr;
        unordered_set<UndirectedGraphNode *> visited;
        
        queue<UndirectedGraphNode *> data;
        if (node) {
            data.push(node);
            visited.insert(node);
        }
        while (!data.empty()) {
            auto curr = data.front();
            data.pop();
            if (!m.count(curr))
                m[curr] = new UndirectedGraphNode(curr->label);
            for (auto neighbor : curr->neighbors) {
                if (!m.count(neighbor))
                    m[neighbor] = new UndirectedGraphNode(neighbor->label);
                m[curr]->neighbors.push_back(m[neighbor]);
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    data.push(neighbor);
                }
            }
        }
        return m[node];
    }
};