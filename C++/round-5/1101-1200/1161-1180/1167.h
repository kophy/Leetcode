class Solution {
public:
  int connectSticks(vector<int> &sticks) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> candidates;
    for (int stick : sticks) {
      candidates.push(stick);
    }
    int cost = 0;
    while (candidates.size() > 1) {
      int s1 = candidates.top();
      candidates.pop();
      int s2 = candidates.top();
      candidates.pop();

      candidates.push(s1 + s2);
      cost += (s1 + s2);
    }
    return cost;
  }
};