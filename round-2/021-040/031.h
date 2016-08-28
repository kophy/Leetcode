class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int front, back;
        for (front = nums.size() - 1; front > 0; --front) {

            /* nums[front - 1] and nums[front] is the first in-order pair */
            if (nums[front - 1] < nums[front]) {
                back = nums.size() - 1;

                /* find the smallest element to replace nums[front - 1] */
                while (nums[front - 1] >= nums[back])
                    --back;
                swap(nums[front - 1], nums[back]);
                break;
            }
        }

        /* fix the back part */
        reverse(nums.begin() + front, nums.end());
    }
};