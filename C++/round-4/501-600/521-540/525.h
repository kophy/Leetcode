class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        replace(nums.begin(), nums.end(), 0, -1);
        
        unordered_map<int, int> sum2idx;
        sum2idx[0] = -1;
        
        int max_length = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum2idx.count(sum))
                max_length = max(max_length, i - sum2idx[sum]);
            else
                sum2idx[sum] = i;
        }
        return max_length;
    }
};