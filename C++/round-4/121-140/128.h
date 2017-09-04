class Solution {
public:
	int longestConsecutive(vector<int> &nums) {
		// Mapping between value and length of consecutive suquence is not always valid.
		unordered_map<int, int> data;
		int max_length = 0;
for (int &num : nums) {
			// Same num later will causes errorly long sequence.
			// We only check whether new num can link two existent sequences.
			if (data.find(num) != data.end())
				continue;
			int left = 0, right = 0;
			if (data.find(num - 1) != data.end())
				left = data[num - 1];
			if (data.find(num + 1) != data.end())
				right = data[num + 1];
			int length = left + 1 + right;
			data[num] = length;
			data[num - left] = length;
			data[num + right] = length;

			max_length = max(length, max_length);
		}
		return max_length;
	}
};