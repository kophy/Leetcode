class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int begin = 0, end = -1;
        
        // find begin of last increasing subarray with minimum larger than all elements before
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            mx = max(mx, nums[i]);
            if (nums[i] != mx)
                end = i;
        }
        
        // find begin of last decreasing subarry with maximum smaller than all elements before (revrese)
        int mn = INT_MAX;
        for (int j = (int)nums.size() - 1; j >= 0; --j) {
            mn = min(mn, nums[j]);
            if (nums[j] != mn)
                begin = j;
        }

        return (end - begin + 1);
    }
};