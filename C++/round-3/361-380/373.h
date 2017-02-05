class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty())
            return result;
        auto cmp = [&nums1, &nums2](pair<int, int> &a, pair<int, int> &b) -> bool {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
        data.push(make_pair(0, 0));
        for (int i = 0; i < k && !data.empty(); ++i) {
            auto temp = data.top();
            data.pop();
            result.push_back(make_pair(nums1[temp.first], nums2[temp.second]));
            if (temp.first + 1 < nums1.size())
                data.push(make_pair(temp.first + 1, temp.second));
            if (temp.first == 0 && temp.second + 1 < nums2.size())
                data.push(make_pair(temp.first, temp.second + 1));
        }
        return result;
    }
};