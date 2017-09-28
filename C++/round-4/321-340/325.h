class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        // classic trick of presum and map
        unordered_map<int, int> sum2idx;
        sum2idx[0] = -1;
        
        int sum = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum2idx.count(sum - k))
                result = max(result, i - sum2idx[sum - k]);
            if (!sum2idx.count(sum))
                sum2idx[sum] = i;
        }
        return result;
    }
};