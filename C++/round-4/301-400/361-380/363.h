// compexity: O(M^2 * N * lgN)
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		int M = matrix.size(), N = matrix[0].size();

		int result = INT_MIN;
		for (int d = 0; d < M; ++d) {
			vector<int> v(N, 0);
			for (int u = d; u < M; ++u) {
				for (int j = 0; j < N; ++j)
					v[j] += matrix[u][j];
				result = max(result, maxSumSubVector(v, k));
			}
		}
		return result;
	}

private:
	int maxSumSubVector(vector<int> &v, int k) {
		int result = INT_MIN;
		int sum = 0;
		set<int> presum;
		presum.insert(0);   // index can start from 0!
for (int &num : v) {
			sum += num;
			auto iter = presum.lower_bound(sum - k);
			if (iter != presum.end())
				result = max(result, sum - *iter);
			presum.insert(sum);
		}
		return result;
	}
};