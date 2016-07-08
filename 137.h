class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if ((nums[j] >> i) & 0x0001 == 0x0001)
                    ++sum;
            }
            if (sum % 3)
                result |= 1 << i;
        }
        return result;
    }
};