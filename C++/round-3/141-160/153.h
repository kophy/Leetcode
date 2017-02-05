class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = (int)nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[high])
                high = mid;
            else
                low = mid + 1;
        }
        return nums[low];
    }
};