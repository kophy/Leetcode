/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return nullptr;
        map<UndirectedGraphNode *, UndirectedGraphNode *> node_map;
        queue<UndirectedGraphNode *> data;
        set<UndirectedGraphNode *> visited;

        data.push(node);
        while (!data.empty()) {
            UndirectedGraphNode *curr = data.front();
            visited.insert(curr);
            data.pop();
            if (node_map.find(curr) == node_map.end())
                node_map[curr] = new UndirectedGraphNode(curr->label);

            for (int i = 0; i < curr->neighbors.size(); ++i) {
                if (node_map.find(curr->neighbors[i]) == node_map.end())
                    node_map[curr->neighbors[i]] = new UndirectedGraphNode(curr->neighbors[i]->label);
                node_map[curr]->neighbors.push_back(node_map[curr->neighbors[i]]);
                if (visited.find(curr->neighbors[i]) == visited.end()) {
                    visited.insert(curr->neighbors[i]);
                    data.push(curr->neighbors[i]);
                }
            }
        }
        return node_map[node];
    }
};