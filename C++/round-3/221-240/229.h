class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0, n2 = 1;
        int c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num == n1)
                ++c1;
            else if (num == n2)
                ++c2;
            else if (c1 == 0) {
                n1 = num;
                c1 = 1;
            } else if (c2 == 0) {
                n2 = num;
                c2 = 1;
            } else {
                --c1;
                --c2;
            }
        }
        c1 = 0;
        c2 = 0;
        for (int num : nums) {
            if (num == n1)
                ++c1;
            if (num == n2)
                ++c2;
        }
        vector<int> result;
        int threshold = nums.size() / 3;
        if (c1 > threshold)
            result.push_back(n1);
        if (c2 > threshold)
            result.push_back(n2);
        return result;
    }
};