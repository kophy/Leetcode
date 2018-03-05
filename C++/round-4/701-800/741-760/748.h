class Solution {
 public:
  string shortestCompletingWord(string licensePlate, vector<string> &words) {
    vector<int> lv = makeVector(licensePlate);
    string result;
    for (string &word : words) {
      vector<int> wv = makeVector(word);
      if (canComplete(lv, wv) &&
          (result.empty() || result.size() > word.size()))
        result = word;
    }
    return result;
  }

 private:
  vector<int> makeVector(string &s) {
    vector<int> v(26);
    for (char c : s)
      if (isalpha(c)) ++v[tolower(c) - 'a'];
    return v;
  }

  bool canComplete(vector<int> &lv, vector<int> &wv) {
    for (int i = 0; i < 26; ++i)
      if (lv[i] > wv[i]) return false;
    return true;
  }
};
