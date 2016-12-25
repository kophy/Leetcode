class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count1;
        for (int num : nums1)
            ++count1[num];
        vector<int> result;
        for (int num : nums2)
            if (count1.find(num) != count1.end() && count1[num] > 0) {
                --count1[num];
                result.push_back(num);
            }
        return result;
    }
};