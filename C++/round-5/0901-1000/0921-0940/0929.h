class Solution {
 public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_map<string, unordered_set<string>> domain_to_locals;
    for (const auto &email : emails) {
      pair<string, string> p = parseEmail(email);
      domain_to_locals[p.first].insert(p.second);
    }
    int count = 0;
    for (const auto &p : domain_to_locals) {
      count += p.second.size();
    }
    return count;
  }

 private:
  pair<string, string> parseEmail(const string &email) {
    int at = email.find('@');
    string domain = email.substr(at + 1);
    string local;
    for (int i = 0; i < at; ++i) {
      if (email[i] == '+') {
        break;
      } else if (email[i] != '.') {
        local.push_back(email[i]);
      }
    }
    return make_pair(local, domain);
  }
};
