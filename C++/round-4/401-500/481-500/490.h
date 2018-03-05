class Solution {
public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        if (maze.empty() || maze[0].empty())
            return false;
        M = maze.size();
        N = maze[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        return dfs(maze, visited, start, destination);
    }
    
private:
    int M, N;
    
    bool valid(int x, int y) {
        return x >= 0 && x < M&& y >= 0 && y < N;
    }
    
    bool dfs(vector<vector<int>> &maze, vector<vector<bool>> &visited, vector<int> &start, vector<int> &destination) {
        int x = start[0], y = start[1];
        visited[x][y] = true;
        
        // case 1: reach destination
        if (x == destination[0] && y == destination[1])
            return true;
        
        // case 2: try 4 directions
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};        
        for (int k = 0; k < 4; ++k) {
            int nx = x, ny = y;
            
            // this part guarantees stop point is valid!
            while (valid(nx + dx[k], ny + dy[k]) && maze[nx + dx[k]][ny + dy[k]] != 1) {
                nx += dx[k];
                ny += dy[k];
            }
            if (!visited[nx][ny]) {
                vector<int> temp = {nx, ny};
                if (dfs(maze, visited, temp, destination))
                    return true;
            }
        }
        return false;
    }
};