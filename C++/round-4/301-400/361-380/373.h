class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](pair<int, int> &a, pair<int, int> &b) -> bool {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] +  nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
        if (nums1.size() && nums2.size())
            data.push(make_pair(0, 0));
        
        vector<pair<int, int>> result;
        for (int i = 0; i < k && !data.empty(); ++i) {
            auto p = data.top();
            data.pop();
            result.push_back(make_pair(nums1[p.first], nums2[p.second]));
            
            if (p.second + 1 < nums2.size())
                data.push(make_pair(p.first, p.second + 1));
            if (p.second == 0 && p.first + 1 < nums1.size())
                data.push(make_pair(p.first + 1, p.second));
        }
        return result;
    }
};