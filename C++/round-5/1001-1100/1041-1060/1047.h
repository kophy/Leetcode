class Solution {
public:
  string removeDuplicates(string S) {
    stack<char> removed;
    for (char c : S) {
      if (!removed.empty() && removed.top() == c) {
        removed.pop();
      } else {
        removed.push(c);
      }
    }
    string result;
    while (!removed.empty()) {
      result.push_back(removed.top());
      removed.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};