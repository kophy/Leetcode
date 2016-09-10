class Solution {
public:
    /*  ab c -> ab
        00 0 -> 00 (0)
        00 1 -> 01 (1)
        01 0 -> 01 (1)
        01 1 -> 10 (2)
        10 0 -> 10 (2)
        10 1 -> 00 (3)
    */
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int c = nums[i];
            int temp = (~a & b & c) | (a & ~b & ~c);
            b = (~a & ~b & c) | (~a & b & ~c);
            a = temp;
        }
        return a | b;
    }
};