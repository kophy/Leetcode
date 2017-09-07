// same idea as arrow burst and russian envelope
class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), [](vector<int> &p, vector<int> &q)->bool {
			return p[1] < q[1];
		});
		int count = 1;
		vector<int> &tail = pairs[0];
		for (int i = 1; i < pairs.size(); ++i) {
			if (pairs[i][0] > tail[1]) {
				tail = pairs[i];
				++count;
			}
		}
		return count;
	}
};