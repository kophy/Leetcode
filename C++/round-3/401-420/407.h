class Solution {
public:
    int trapRainWater(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		M = matrix.size();
		N = matrix[0].size();
		vector<vector<bool>> visited(M, vector<bool>(N, false));
		auto cmp = [](cell &a, cell &b) -> bool {
			return a.height > b.height;
		};
		priority_queue<cell, vector<cell>, decltype(cmp)> data(cmp);
		
		// start with outer bound
		for (int i = 0; i < M; ++i) {
			if (!visited[i][0]) {
				visited[i][0] = true;
				data.push(cell(i, 0, matrix[i][0]));
			}
			if (!visited[i][N - 1]) {
				visited[i][N - 1] = true;
				data.push(cell(i, N - 1, matrix[i][N - 1]));
			}
		}
		for (int j = 0; j < N; ++j) {
			if (!visited[0][j]) {
				visited[0][j] = true;
				data.push(cell(0, j, matrix[0][j]));
			}
			if (!visited[M - 1][j]) {
				visited[M - 1][j] = true;
				data.push(cell(M - 1, j, matrix[M - 1][j]));
			}
		}
		
		// shrink and add volumn
		int result = 0;
		int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};
		while (!data.empty()) {
			cell temp = data.top();
			data.pop();
			for (int k = 0; k < 4; ++k) {
				int r = temp.row + dr[k], c = temp.col + dc[k];
				if (!isValidIndex(r, c) || visited[r][c])
					continue;
				visited[r][c] = true;
				if (matrix[r][c] < temp.height)
					result += temp.height - matrix[r][c];
				data.push(cell(r, c, max(matrix[r][c], temp.height)));
			}
		}
		return result;
    }
    
private:
	int M, N;
	
	bool isValidIndex(int r, int c) {
		return r >= 0 && r < M && c >= 0 && c < N;
	}
	
	typedef struct cell {
		int row;
		int col;
		int height;
		cell(int r, int c, int h) {
			row = r;
			col = c;
			height = h;
		}
	} cell;
};