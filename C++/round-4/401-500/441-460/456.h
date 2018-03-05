class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        vector<int> pse(nums.size());    // previous smallest element
        vector<int> pgei(nums.size());   // previous greater element index
        
        stack<int> data;
        int minimum = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            while (!data.empty() && nums[data.top()] <= nums[i])
                data.pop();
            pgei[i] = data.empty()? -1 : data.top();
            pse[i] = minimum;
            
            data.push(i);
            minimum = min(minimum, nums[i]);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (pgei[i] >= 0 && pse[pgei[i]] < nums[i])
                return true;
        }
        return false;
    }
};