class Solution {
public:
	Solution(vector<int> nums) {
		data = nums;
	}

	int pick(int target) {
		int result = -1, count = 0;
		for (int i = 0; i < data.size(); ++i) {
			if (data[i] != target)
				continue;
			++count;
			if (rand() % count == 0)
				result = i;
		}
		return result;
	}

private:
	vector<int> data;
};