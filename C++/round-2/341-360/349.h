class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> data;
        for (int i = 0; i < nums1.size(); ++i)
            data.insert(nums1[i]);
        vector<int> result;
        for (int i = 0; i < nums2.size(); ++i)
            if (data.find(nums2[i]) != data.end()) {
                result.push_back(nums2[i]);
                data.erase(nums2[i]);
            }
        return result;
    }
};