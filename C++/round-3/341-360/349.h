class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        for (int num : nums1)
            set1.insert(num);
        unordered_set<int> interset;
        for (int num : nums2)
            if (set1.count(num))
                interset.insert(num);
        vector<int> result;
        for (auto iter = interset.begin(); iter != interset.end(); ++iter)
            result.push_back(*iter);
        return result;
    }
};