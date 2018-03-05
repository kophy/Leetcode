// version 1: multiset O(NlgK)
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		multiset<int> window;
		for (int i = 0; i < nums.size(); ++i) {
			window.insert(nums[i]);
			if (i - k >= 0)
				window.erase(window.find(nums[i - k]));
			if (i >= k - 1)
				result.push_back(*(window.rbegin()));
		}
		return result;
	}
};

// version 2: deque O(N)
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		deque<int> window;
		for (int i = 0; i < nums.size(); ++i) {
			if (!window.empty() && window.front() == i - k)
				window.pop_front();
			while (!window.empty() && nums[window.back()] < nums[i])
				window.pop_back();
			window.push_back(i);
			if (i >= k - 1)
				result.push_back(nums[window.front()]);
		}
		return result;
	}
};