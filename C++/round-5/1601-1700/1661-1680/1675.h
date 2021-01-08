class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    priority_queue<int> max_queue;
    int min_element = INT_MAX;
    for (int num : nums) {
      if (num % 2 == 1) {
        num *= 2;
      }
      max_queue.push(num);
      min_element = min(min_element, num);
    }

    int result = max_queue.top() - min_element;
    while (true) {
      int max_element = max_queue.top();
      max_queue.pop();
      result = min(result, max_element - min_element);

      if (max_element % 2 == 1) {
        break;
      } else {
        max_queue.push(max_element / 2);
        min_element = min(min_element, max_element / 2);
      }
    }
    return result;
  }
};