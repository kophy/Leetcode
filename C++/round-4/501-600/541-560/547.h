class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        if (M.empty())
            return 0;
        vector<int> labels(M.size());
        for (int i = 0; i < labels.size(); ++i)
            labels[i] = i;
        for (int i = 0; i < M.size(); ++i)
            for (int j = i + 1; j < M.size(); ++j)
                if (M[i][j] == 1)
                    unionLabels(labels, i, j);
        
        unordered_set<int> circles;
        for (int i = 0; i < labels.size(); ++i)
            circles.insert(findLabel(labels, i));
        return circles.size();
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