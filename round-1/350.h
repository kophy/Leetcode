class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> count;

        for (int i = 0; i < nums1.size(); ++i)
            ++count[nums1[i]];

        for (int j = 0; j < nums2.size(); ++j) {
            if (count.find(nums2[j]) != count.end() && count[nums2[j]] > 0) {
                result.push_back(nums2[j]);
                --count[nums2[j]];
            }
        }
        return result;
    }
};