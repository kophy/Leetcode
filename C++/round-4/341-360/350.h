class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt1, cnt2, cnt;
        for (int num : nums1)
            ++cnt1[num];
        for (int num : nums2)
            ++cnt2[num];
        
        vector<int> result;
        for (auto &p : cnt1) {
            if (cnt2.count(p.first)) {
                for (int i = 0; i < min(p.second, cnt2[p.first]); ++i)
                    result.push_back(p.first);
            }
        }
        return result;
    }
};