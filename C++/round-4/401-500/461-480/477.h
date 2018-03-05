class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        // handle special cases
        if (nums.size() <= 1)
            return 0;
        // count 1 at each position
        vector<int> count(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 32; ++i)
                if ((num & (1 << i)))
                    ++count[i];
        }
        // calculate total distance
        int result = 0;
        int N = nums.size();
        for (int i = 0; i < 32; ++i)
            result += count[i] * (N - count[i]);
        return result;
    }
};