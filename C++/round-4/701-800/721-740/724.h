class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int N = nums.size();
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; ++i)
            presum[i + 1] = presum[i] + nums[i];
        for (int i = 0; i < N; ++i) {
            if (presum[i] - presum[0] == presum[N] - presum[i + 1])
                return i;
        }
        return -1;
    }
};