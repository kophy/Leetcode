class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for (int num : nums)
            temp ^= num;
        bitset<32> mask(temp);
        int k = 0;
        while (!mask[k])
            ++k;
        vector<int> result(2, 0);
        for (int num : nums) {
            bitset<32> curr(num);
            result[curr[k]? 1 : 0] ^= num;
        }
        return result;
    }
};