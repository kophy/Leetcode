class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

        /* find rightmost set bit */
        int mask = diff & ~(diff - 1);

        /* partition nums into two groups according to mask */
        vector<int> result(2, 0);
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] & mask) == 0)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];
        }
        return result;
    }
};