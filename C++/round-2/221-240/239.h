class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> data;

        for (int i = 0; i < nums.size(); ++i) {
            /* discard elements beyond sliding window */
            if (data.size() && i - data.front() >= k)
                data.pop_front();

            /* dicard elements in the window smaller than current element(won't be used any more) */
            while (data.size() && nums[data.back()] < nums[i])
                data.pop_back();

            data.push_back(i);

            /* the deque is in descending order, so the front element is the largest */
            if (i >= k - 1)
                result.push_back(nums[data.front()]);
        }

        return result;
    }
};