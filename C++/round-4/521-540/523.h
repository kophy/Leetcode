class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        k = abs(k);
        
        unordered_map<int, int> sum2idx;
        sum2idx[0] = -1;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (k == 0) {
                if (sum2idx.count(sum) && i - sum2idx[sum] >= 2)
                    return true;
            } else {
                for (auto &p : sum2idx) {
                    if ((sum - p.first) % k == 0 && i - p.second >= 2)
                        return true;
                }
            }
            if (!sum2idx.count(sum))
                sum2idx[sum] = i;
        }
        return false;
    }
};