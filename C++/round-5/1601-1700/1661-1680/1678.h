class Solution {
 public:
  string interpret(string command) {
    stringstream ss;
    int i = 0;
    while (i < command.size()) {
      if (command[i] == 'G') {
        ss << "G";
        ++i;
      } else if (command[i] == '(' && command[i + 1] == ')') {
        ss << "o";
        i += 2;
      } else {
        ss << "al";
        i += 4;
      }
    }
    return ss.str();
  }
};