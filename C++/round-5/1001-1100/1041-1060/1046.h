class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int, vector<int>, std::less<int>> left_stones;
    for (int stone : stones) {
      left_stones.push(stone);
    }
    while (left_stones.size() > 1) {
      int s1 = left_stones.top();
      left_stones.pop();
      int s2 = left_stones.top();
      left_stones.pop();
      if (s1 != s2) {
        left_stones.push(abs(s1 - s2));
      }
    }
    return left_stones.empty() ? 0 : left_stones.top();
  }
};