class NumArray {
public:
	NumArray(vector<int> nums) {
		presum = vector<int>(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); ++i)
			presum[i + 1] = presum[i] + nums[i];
	}

	int sumRange(int i, int j) {
		return presum[j + 1] - presum[i];
	}

private:
	vector<int> presum;
};
