class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        M = grid.size();
        N = grid[0].size();
        
        queue<pair<int, int>> data;
        int fresh_oranges = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    ++fresh_oranges;
                } else if (grid[i][j] == 2) {
                    data.push(std::make_pair(i, j));
                }
            }
        }
        
        if (fresh_oranges == 0) {
            return 0;
        }
        
        int minutes = 0;
        while (!data.empty()) {
            ++minutes;
            queue<pair<int, int>> next;
            while (!data.empty()) {
                int x = data.front().first, y = data.front().second;
                data.pop();
                
                int dxs[] = {-1, 0, 1, 0};
                int dys[] = {0, -1, 0, 1};
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dxs[k], ny = y + dys[k];
                    if (!isValid(nx, ny) || grid[nx][ny] != 1) {
                        continue;
                    }
                    if (--fresh_oranges == 0) {
                        return minutes;
                    }
                    grid[nx][ny] = 2;
                    next.push(std::make_pair(nx, ny));
                }
            }
            data = next;
        }
        return -1;
    }
    
private:
    int M;
    int N;
    
    bool isValid(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }
};