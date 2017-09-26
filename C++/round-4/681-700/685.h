class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> father;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            // case 1: multiple fathers
            if (father.count(v) && father[v] != u)
                return edge;
            father[v] = u;
            // case 2: has cycle (new edge must be in the cycle)
            if (hasCycle(father, v))
                return edge;
        }
        return {};
    }
    
private:
    bool hasCycle(unordered_map<int, int> &father, int v) {
        for (int node = father[v]; father.count(node); node = father[node]) {
            if (node == v)
                return true;
        }
        return false;
    }
};