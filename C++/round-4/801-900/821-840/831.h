class Solution {
 public:
  string maskPII(string S) {
    if (S.find('@') != string::npos) return maskEmail(S);
    return maskPhone(S);
  }

 private:
  string maskEmail(const string &S) {
    int n = S.find('@');
    string name = S.substr(0, n), rest = S.substr(n);
    string masked_name =
        string(1, name[0]) + "*****" + string(1, name[name.size() - 1]);
    string masked_S = masked_name + rest;
    transform(masked_S.begin(), masked_S.end(), masked_S.begin(), ::tolower);
    return masked_S;
  }

  string maskPhone(const string &S) {
    string data;
    for (char c : S) {
      if (isdigit(c)) {
        data.push_back(c);
      }
    }
    if (data.size() == 10) {
      return "***-***-" + data.substr(data.size() - 4);
    } else {
      return "+" + string(data.size() - 10, '*') + "-***-***-" +
             data.substr(data.size() - 4);
    }
  }
};
