class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        unordered_map<int, int> m;
        int count = 0;
        for (auto &edge : edges) {
            if (!m.count(edge[0]))
                m[edge[0]] = count++;
            if (!m.count(edge[1]))
                m[edge[1]] = count++;
        }
        
        vector<int> labels(m.size());
        for (int i = 0; i < labels.size(); ++i)
            labels[i] = i;
        for (auto &edge : edges) {
            int id0 = m[edge[0]], id1 = m[edge[1]];
            if (findLabel(labels, id0) == findLabel(labels, id1))
                return edge;
            unionLabels(labels, id0, id1);
        }
        return edges.back();
    }
    
private:
    int findLabel(vector<int> &labels, int i) {
        if (labels[i] != i)
            labels[i] = findLabel(labels, labels[i]);
        return labels[i];
    }
    
    void unionLabels(vector<int> &labels, int i, int j) {
        labels[findLabel(labels, i)] = findLabel(labels, j);
    }
};