class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size() + nums2.size();
        if (l % 2)
            return findKthElement(nums1, nums2, l / 2 + 1);
        else
            return (findKthElement(nums1, nums2, l / 2 + 1) + findKthElement(nums1, nums2, l / 2)) / 2.0;
    }
private:
    int findKthElement(vector<int> nums1, vector<int> nums2, int k) {
        if (nums1.size() > nums2.size())
            return findKthElement(nums2, nums1, k);
        if (nums1.size() == 0)
            return nums2[k - 1];
        if (k == 1)
            return min(nums1[0], nums2[0]);

        int p1 = min(k / 2, (int)nums1.size());
        int p2 = k - p1;
        if (nums1[p1 - 1] < nums2[p2 - 1]) {
            vector<int> temp(nums1.begin() + p1, nums1.end());
            return findKthElement(temp, nums2, k - p1);
        } else {
            vector<int> temp(nums2.begin() + p2, nums2.end());
            return findKthElement(nums1, temp, p1);
        }
    }
};