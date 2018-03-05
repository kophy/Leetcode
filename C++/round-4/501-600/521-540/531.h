class Solution {
public:
    int findLonelyPixel(vector<vector<char>> &picture) {
        if (picture.empty() || picture[0].empty())
            return 0;
        int M = picture.size(), N = picture[0].size();
        vector<int> row(M, 0), col(N, 0);
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (picture[i][j] != 'B')
                    continue;
                ++row[i];
                ++col[j];
            }
        }
        
        int result = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1)
                    ++result;
            }
        }
        return result;
    }
};