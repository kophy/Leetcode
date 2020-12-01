class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> val_to_indices;
        for (int i = 0; i < arr.size(); ++i) {
            val_to_indices[arr[i]].push_back(i);
        }
        
        int rank = 1;
        for (const auto &p : val_to_indices) {
            for (int index : p.second) {
                arr[index] = rank;
            }
            ++rank;
        }
        return arr;
    }
};