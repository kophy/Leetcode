class Solution {
 public:
  vector<string> removeComments(vector<string> &source) {
    stringstream ss;
    copy(source.begin(), source.end(), ostream_iterator<string>(ss, "\n"));
    string s = ss.str();

    regex e("//.*|/\\*(.|\n)*?\\*/");
    s = regex_replace(s, e, "");

    vector<string> result;
    ss.str(s);
    string token;
    while (ss.good()) {
      getline(ss, token, '\n');
      if (!token.empty()) result.push_back(token);
    }
    return result;
  }
};
