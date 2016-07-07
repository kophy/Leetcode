class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[mid - 1])
                return nums[mid];
            else if (nums[mid] >= nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};
