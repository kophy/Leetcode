class Solution {
public:
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); ++i)
            data.push_back(make_pair(nums[i], i));
        sort(data.begin(), data.end(), comp);
    }

    int pick(int target) {
        auto bounds = equal_range(data.begin(), data.end(), make_pair(target, 0), comp);
        int s = bounds.first - data.begin(), e = bounds.second - data.begin();
        int r = e - s;
        return data[s + (rand() % r)].second;
    }

private:
    vector<pair<int, int>> data;
    static bool comp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    };
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */