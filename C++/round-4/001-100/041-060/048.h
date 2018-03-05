class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() <= 1)
			return;
		int N = matrix.size();
		for (int i = 0; i < N / 2; ++i) {
			for (int j = 0; j < N; ++j) {
				swap(matrix[i][j], matrix[N - 1 - i][j]);
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < i; ++j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};