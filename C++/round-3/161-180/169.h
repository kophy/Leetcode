class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0, c = 0;
        for (int num : nums) {
            if (num == n)
                ++c;
            else if (c == 0) {
                n = num;
                c = 1;
            }
            else
                --c;
        }
        return n;
    }
};