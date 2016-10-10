class Solution {
public:
    /* binary search */
    int splitArray(vector<int>& nums, int g) {
        long l = 0, r = 0;
        for (int num : nums) {
            l = max(l, (long)num);
            r += num;
        }
        while (l < r) {
            long m = l + (r - l) / 2;
            if (valid(nums, g, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
private:
    /*  check if nums can be splitted into at most g subarrays,
        and has target_sum as their largest sum.
    */
    bool valid(const vector<int>& nums, int g, long target_sum) {
        int curr_sum = 0;
        for (int num : nums) {
            if (curr_sum + num <= target_sum)
                curr_sum += num;
            else {
                if (--g == 0)
                    return false;
                curr_sum = num;
            }
        }
        return true;
    }
};