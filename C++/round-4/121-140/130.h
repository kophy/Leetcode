// version 1: stack overflow (recursion too deep)
class Solution {
public:
	void solve(vector<vector<char>> &board) {
		if (board.size() == 0 || board[0].size() == 0)
			return;
		M = board.size();
		N = board[0].size();
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				if ((i == 0 || i == M - 1 || j == 0 || j == N - 1) && board[i][j] == 'O')
					grow(board, i, j);
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j] = (board[i][j] == '@')? 'O' : 'X';
	}

private:
	int M, N;

	bool isValidIndex(int i , int j) {
		return i >= 0 && i < M && j >= 0 && j < N;
	}

	void grow(vector<vector<char>> &board, int i, int j) {
		board[i][j] = '@';
		int di[] = {-1, 0, 1, 0};
		int dj[] = {0, -1, 0, 1};
		for (int k = 0; k < 4; ++k) {
			int ni = i + di[k], nj = j + dj[k];
			if (isValidIndex(ni, nj) && board[ni][nj] == 'O')
				grow(board, ni, nj);
		}
		return;
	}
};

// version 2: iterative
class Solution {
public:
	void solve(vector<vector<char>> &board) {
		if (board.size() == 0 || board[0].size() == 0)
			return;
		M = board.size();
		N = board[0].size();
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				if ((i == 0 || i == M - 1 || j == 0 || j == N - 1))
					grow(board, i, j);
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j] = (board[i][j] == '@')? 'O' : 'X';
	}

private:
	int M, N;

	bool isValidIndex(int i , int j) {
		return i >= 0 && i < M && j >= 0 && j < N;
	}

	void grow(vector<vector<char>> &board, int i, int j) {
		queue<pair<int, int>> data;
		set<pair<int, int>> visited;
		if (board[i][j] == 'O') {
			pair<int, int> p = make_pair(i, j);
			data.push(p);
			visited.insert(p);
		}
		int dx[] = {-1, 0, 1, 0};
		int dy[] = {0, -1, 0, 1};
		while (!data.empty()) {
			int x = data.front().first, y = data.front().second;
			data.pop();
			board[x][y] = '@';
			for (int k = 0; k < 4; ++k) {
				int nx = x + dx[k], ny = y + dy[k];
				pair<int, int> np = make_pair(nx, ny);
				if ((!isValidIndex(nx, ny)) || board[nx][ny] != 'O' || visited.find(np) != visited.end())
					continue;
				data.push(np);
				visited.insert(np);
			}
		}
	}
};