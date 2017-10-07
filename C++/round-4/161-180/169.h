class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int candidate = nums[0], count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else {
                --count;
                if (count < 0) {
                    candidate = num;
                    count = 1;
                }
            }
        }
        return candidate;
    }
};