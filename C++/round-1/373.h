class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty())
            return result;
        auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
        data.emplace(0, 0);
        while (k-- > 0 && !data.empty()) {
            pair<int, int> temp = data.top();
            data.pop();
            result.push_back(pair<int, int>(nums1[temp.first], nums2[temp.second]));
            if (temp.first + 1 < nums1.size())
                data.emplace(pair<int, int>(temp.first + 1, temp.second));
            if (temp.first == 0 && temp.second + 1 < nums2.size())
                data.emplace(pair<int, int>(temp.first, temp.second + 1));
        }
        return result;
    }
};