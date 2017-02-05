class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
		vector<double> result;
		multiset<int> window;
		for (int i = 0; i < nums.size(); ++i) {
			window.insert(nums[i]);
			if (window.size() > k)
				window.erase(window.find(nums[i - k]));
			if (window.size() == k)
			result.push_back(getMedian(window));
		}
		return result;
    }
	
private:
	double getMedian(multiset<int> &window) {
		int size = window.size();
		if (size % 2 == 1) {
			auto iter = window.begin();
			for (int i = 0; i < size / 2; ++i)
				++iter;
			return *iter;
		} else {
			auto iter1 = window.begin();
			for (int i = 0; i < size / 2; ++i)
				++iter1;
			auto iter2 = iter1;
			--iter2;
			return (double(*iter1) + double(*iter2)) / 2.0;
		}
	}
};