class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int max_pre = nums[0], min_pre = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            vector<int> candidates = {max_pre * nums[i], min_pre * nums[i], nums[i]};
            int max_curr = *max_element(candidates.begin(), candidates.end());
            int min_curr = *min_element(candidates.begin(), candidates.end());
            
            max_pre = max_curr;
            min_pre = min_curr;
            result = max(result, max_pre);
        }
        return result;
    }
};