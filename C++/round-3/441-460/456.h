class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s3;
        int s2 = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < s2)
                return true;
            else {
                // s2 is the largest element with a larger element on its left
                while (!s3.empty() && nums[i] > s3.top()) {
                    s2 = s3.top();
                    s3.pop();
                }
            }
            s3.push(nums[i]);
        }
        return false;
    }
};