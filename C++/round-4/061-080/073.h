class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return;
		int M = matrix.size(), N = matrix[0].size();

		bool set_first_row = false, set_first_col = false;
		for (int j = 0; j < N; ++j)
			if (matrix[0][j] == 0)
				set_first_row = true;
		for (int i = 0; i < M; ++i)
			if (matrix[i][0] == 0)
				set_first_col = true;

		for (int i = 1; i < M; ++i) {
			for (int j = 1; j < N; ++j) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = 1; i < M; ++i)
			for (int j = 1; j < N; ++j)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
		if (set_first_row) {
			for (int j = 0; j < N; ++j)
				matrix[0][j] = 0;
		}
		if (set_first_col) {
			for (int i = 0; i < M; ++i)
				matrix[i][0] = 0;
		}
	}
};