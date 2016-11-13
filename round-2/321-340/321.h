class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int M = nums1.size(), N = nums2.size();
        vector<int> result;
        for (int k1 = max(k - N, 0); k1 <= min(k, M); ++k1)
            result = max(result, merge(maxNumber(nums1, k1),
                                       maxNumber(nums2, k - k1)));
        return result;
    }

private:
    vector<int> maxNumber(vector<int> nums, int k) {
        int drop = nums.size() - k;
        vector<int> out;
        for (int num : nums) {
            while (drop && out.size() && out.back() < num) {
                out.pop_back();
                --drop;
            }
            out.push_back(num);
        }
        out.resize(k);
        return out;
    }

    // two vectors are not sorted!
    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> out;
        while (nums1.size() + nums2.size()) {
            // can't choose freely when nums1[0] == nums2[0]
            vector<int>& now = nums1 > nums2 ? nums1 : nums2;
            out.push_back(now[0]);
            now.erase(now.begin());
        }
        return out;
    }
};