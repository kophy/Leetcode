class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();

        /* the min heap containing K greatest elements */
        priority_queue<int, vector<int>, greater<int>> data;
        for (int i = 0; i < nums.size(); ++i) {
            if (data.size() < k)
                data.push(nums[i]);
            else if (data.top() < nums[i]) {
                data.pop();
                data.push(nums[i]);
            }
        }
        return data.top();
    }
};