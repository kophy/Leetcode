class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        multiset<int> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k)
                window.erase(window.find(nums[i - k]));
            window.insert(nums[i]);
            if (window.size() == k)
                result.push_back(*window.rbegin());
        }
        return result;
    }
};