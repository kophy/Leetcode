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
        map<UndirectedGraphNode *, UndirectedGraphNode *> nodemap;
        nodemap[NULL] = NULL;

        queue<UndirectedGraphNode *> data;
        set<UndirectedGraphNode *> visited;
        if (node) {
            data.push(node);
            visited.insert(node);
        }

        while (!data.empty()) {
            auto temp = data.front();
            data.pop();

            if (nodemap.find(temp) == nodemap.end())
                nodemap[temp] = new UndirectedGraphNode(temp->label);
            for (int i = 0; i < temp->neighbors.size(); ++i) {
                auto neighbor = temp->neighbors[i];
                if (nodemap.find(neighbor) == nodemap.end())
                    nodemap[neighbor] = new UndirectedGraphNode(neighbor->label);
                nodemap[temp]->neighbors.push_back(nodemap[neighbor]);

                if (visited.find(neighbor) == visited.end()) {
                    data.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        return nodemap[node];
    }
};