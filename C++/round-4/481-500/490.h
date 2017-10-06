class Solution {
public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        if (maze.empty() || maze[0].empty())
            return false;
        M = maze.size();
        N = maze[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        visited[start[0]][start[1]] = true;
        return dfs(maze, visited, start, destination);
    }
    
private:
    int M, N;
    
    bool isValid(int x, int y) {
        return x >= 0 && x < M && y >= 0 && y < N;
    }
    
    bool dfs(vector<vector<int>> &maze, vector<vector<bool>> &visited, vector<int> &start, vector<int> &destination) {
        if (start[0] == destination[0] && start[1] == destination[1])
            return true;
        int x = start[0], y = start[1];
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        
        for (int k = 0; k < 4; ++k) {
            int nx = x, ny = y;
            while (isValid(nx + dx[k], ny + dy[k]) && maze[nx + dx[k]][ny + dy[k]] != 1) {
                nx += dx[k];
                ny += dy[k];
            }
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                vector<int> temp = {nx, ny};
                if (dfs(maze, visited, temp, destination))
                    return true;
            }
        }
        return false;
    }
};