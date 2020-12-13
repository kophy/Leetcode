class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        if (arr.empty() || arr[0].empty()) {
            return 0;
        }
        int M = arr.size(), N = arr[0].size();
        
        for (int i = 0; i < M - 1; ++i) {
            int min_index = -1, second_min_index = -1;
            for (int j = 0; j < N; ++j) {
                if (min_index == -1) {
                    min_index = j;
                } else if (arr[i][j] < arr[i][min_index]) {
                    second_min_index = min_index;
                    min_index = j;
                } else if (second_min_index == -1 || arr[i][j] < arr[i][second_min_index]) {
                    second_min_index = j;
                }
            }
            
            for (int j = 0; j < N; ++j) {
                int presum = (j == min_index)? arr[i][second_min_index] : arr[i][min_index];
                arr[i + 1][j] += presum;
            }
        }
        
        return *min_element(arr[M - 1].begin(), arr[M - 1].end());
    }
};