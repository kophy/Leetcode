class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    int i = 0;
    for (int x : pushed) {
      s.push(x);
      while (!s.empty() && i < popped.size() && s.top() == popped[i]) {
        s.pop();
        ++i;
      }
    }
    while (i < popped.size()) {
      if (s.top() != popped[i]) {
        return false;
      }
      s.pop();
    }
    return true;
  }
};
