class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;
		M = grid.size();
		N = grid[0].size();

		int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

		vector<int> labels(M * N);
		for (int i = 0; i < M * N; ++i)
			labels[i] = i;

		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (grid[i][j] != '1')
					continue;
				for (int k = 0; k < 4; ++k) {
					int ni = i + dx[k], nj = j + dy[k];
					if (isValidIndex(ni, nj) && grid[ni][nj] == '1')
						unionLabels(labels, encode(i, j), encode(ni, nj));
				}
			}
		}

		unordered_set<int> islands;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (grid[i][j] != '1')
					continue;
				islands.insert(findLabel(labels, encode(i, j)));
			}
		}
		return islands.size();
	}

private:
	int M, N;

	bool isValidIndex(int i, int j) {
		return i >= 0 && i < M && j >= 0 && j < N;
	}

	int encode(int i, int j) {
		return i * N + j;
	}

	int findLabel(vector<int> &labels, int i) {
		if (labels[i] != i)
			labels[i] = findLabel(labels, labels[i]);
		return labels[i];
	}

	void unionLabels(vector<int> &labels, int i, int j) {
		labels[findLabel(labels, i)] = findLabel(labels, j);
	}
};