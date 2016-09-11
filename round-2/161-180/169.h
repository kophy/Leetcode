class Solution {
public:
    /* reservoir pooling */
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        int num = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == num)
                ++count;
            else
                --count;
            if (count == 0) {
                num = nums[i];
                count = 1;
            }
        }
        return num;
    }
};