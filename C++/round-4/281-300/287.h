// version 1: radix sort
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int N = nums.size() - 1;
		vector<int> bucket(N + 1, 0);
		for (int num : nums)
			if (++bucket[num] > 1)
				return num;
		return 0;
	}
};

// version 2: binary search
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int l = 1, r = (int)nums.size() - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			int cnt = 0;
			for (int num : nums)
				if (num <= m)
					++cnt;
			if (cnt <= m)
				l = m + 1;
			else
				r = m - 1;
		}
		return l;
	}
};