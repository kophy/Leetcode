class NumArray {
public:
	NumArray(vector<int> &nums) {
		int size = nums.size();
		segtree.resize(2 * size);
		for (int i = size; i < 2 * size; ++i)
			segtree[i] = nums[i - size];
		for (int i = size - 1; i > 0; --i)
			segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
	}

	void update(int i, int val) {
		int n = segtree.size() / 2;
		int pos = i + n;
		int diff = val - segtree[pos];
		while (pos) {
			segtree[pos] += diff;
			pos /= 2;
		}
	}

	int sumRange(int i, int j) {
		int n = segtree.size() / 2;
		i += n;
		j += n;
		int sum = 0;
		while (i <= j) {
			if ((i % 2) == 1)
				sum += segtree[i];
			if ((j % 2) == 0)
				sum += segtree[j];
			i = (i + 1) / 2;
			j = (j - 1) / 2;
		}
		return sum;
	}
private:
	vector<int> segtree;
};