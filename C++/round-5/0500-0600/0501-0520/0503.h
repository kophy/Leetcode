class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    stack<int> data;
    for (int i = (int)nums.size() - 2; i >= 0; --i) {
      data.push(nums[i]);
    }
    vector<int> result(nums.size(), 0);
    for (int i = (int)nums.size() - 1; i >= 0; --i) {
      while (!data.empty() && data.top() <= nums[i]) {
        data.pop();
      }
      result[i] = data.empty() ? -1 : data.top();
      data.push(nums[i]);
    }
    return result;
  }
};
