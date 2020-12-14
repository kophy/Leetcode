class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        unordered_map<int, int> row, column;
        for (const auto& indice : indices) {
            ++row[indice[0]];
            ++column[indice[1]];
        }
        
        int num = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((row[i] + column[j]) % 2 == 1) {
                    ++num;
                }
            }
        }
        return num;
    }
};