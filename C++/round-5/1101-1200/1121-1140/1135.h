class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(),
             [](const vector<int> &a, const vector<int> &b)->bool {
                 return a[2] < b[2];
        });
        
        vector<int> labels(N);
        for (int i = 0; i < N; ++i) {
            labels[i] = i;
        }
        
        int result = 0;
        int partitions = N;
        for (const auto& connection : connections) {
            int i = connection[0] - 1, j = connection[1] - 1;
            if (findLabel(labels, i) != findLabel(labels, j)) {
                // Choose the edge.
                unionLabels(labels, i, j);
                --partitions;
                result += connection[2];
            }
        }
        return (partitions == 1)? result : -1;
    }
    
private:
    int findLabel(vector<int> &labels, int i) {
        if (labels[i] != i) {
            labels[i] = findLabel(labels, labels[i]);
        }
        return labels[i];
    }
    
    void unionLabels(vector<int> &labels, int i, int j) {
        labels[findLabel(labels, i)] = labels[findLabel(labels, j)];
    }
};