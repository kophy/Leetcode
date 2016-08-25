class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int, int>> data;
        for (int i = 0; i < nums.size(); ++i)
            data.push_back(pair<int, int>(nums[i], i));
        sort(data.begin(), data.end(), [](pair<int, int> &a, pair<int, int> &b)->bool {
            return a.first < b.first;
        });
        int slow = 0, fast = 1;
        while (fast < nums.size()) {
            cout << data[fast].first - data[slow].first << endl;
            while ((long)data[fast].first - (long)data[slow].first > t)
                ++slow;
            for (int j = slow; j < fast; ++j) {
                if (abs(data[j].second - data[fast].second) <= k)
                    return true;
            }
            ++fast;
        }
        return false;
    }
};