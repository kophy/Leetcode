class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.push_back(INT_MIN);
        int pos = 0;

        /* go througn the increasing part */
        while (pos + 1 < nums.size() && nums[pos] < nums[pos + 1])
            ++pos;
        return pos;
    }
};