class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> data;
        for (int num : nums) {
            data.push(num);
            if (data.size() > k)
                data.pop();
        }
        return data.top();
    }
};