class Solution {
 public:
  bool isValid(string S) {
    stack<string> data;
    for (char c : S) {
      switch (c) {
        case 'a':
          data.push(string(1, 'a'));
          break;
        case 'b':
          if (data.empty() || data.top() != "a") {
            return false;
          }
          data.top() = "ab";
          break;
        case 'c':
          if (data.empty() || data.top() != "ab") {
            return false;
          }
          data.pop();
          break;
        default:
          return false;
      }
    }
    return data.empty();
  }
};
