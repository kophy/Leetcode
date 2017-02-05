class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;

        vector<int> ones_count(32, 0);
        for (int num : nums) {
            bitset<32> temp(num);
            for (int k = 0; k < 32; ++k)
                ones_count[k] += temp[k];
        }

        int total_distance = 0;
        int N = nums.size();
        for (int k = 0; k < 32; ++k)
            total_distance += ones_count[k] * (N - ones_count[k]);
        return total_distance;
    }
};