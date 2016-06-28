class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> index;
        
        for (int i = 0; i < nums1.size(); ++i)
            index[nums1[i]] = i;
        
        for (int j = 0; j < nums2.size(); ++j)
            if (index.find(nums2[j]) != index.end() && index[nums2[j]] >= 0) {
                result.push_back(nums2[j]);
                index[nums2[j]] = -1;
            }
        return result;
        
    }
};