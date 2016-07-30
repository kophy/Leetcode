class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int front = nums.size() - 1;
        while (front > 0) {
            if (nums[front] > nums[front - 1]) {
                int back = nums.size() - 1;
                while (nums[back] <= nums[front - 1])
                    --back;
                swap(nums[front - 1], nums[back]);
                break;
            }
            --front;
        }
        reverse(nums.begin() + front, nums.end());
    }
};