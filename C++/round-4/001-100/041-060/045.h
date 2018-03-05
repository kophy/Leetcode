class Solution {
public:
	int jump(vector<int>& nums) {
		int max_reach = 0, visited = -1;
		int step = 0;

		// whole queue BFS, but only keep max reach
		while (max_reach < nums.size() - 1) {
			int max_reach_next = 0;
			for (int i = visited + 1; i <= max_reach; ++i)
				max_reach_next = max(max_reach_next, i + nums[i]);
			++step;
			visited = max_reach;
			max_reach = max_reach_next;
		}

		return step;
	}
};