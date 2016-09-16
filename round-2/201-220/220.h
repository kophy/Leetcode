class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        /* sort value-index pair according to value */
        vector<pair<int, int>> data;
        for (int i = 0; i < nums.size(); ++i)
            data.push_back(make_pair(nums[i], i));
        sort(data.begin(), data.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
            return a.first < b.first;
        });

        int slow = 0, fast = 1;
        for (; fast < nums.size(); ++fast) {
            /* make sure difference of value is no larger than t */
            while (long(data[fast].first) - long(data[slow].first) > t)
                ++slow;

            /* find if two elements in the range having difference no large than k */
            for (int i = slow; i < fast; ++i)
                if (abs(data[fast].second - data[i].second) <= k)
                    return true;
        }
        return false;
    }
};