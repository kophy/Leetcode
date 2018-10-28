class Solution {
 public:
  vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
    vector<int> universal_vec(26, 0);
    for (auto &word : B) {
      vector<int> v = getLetterVec(word);
      for (int i = 0; i < 26; ++i) {
        universal_vec[i] = max(universal_vec[i], v[i]);
      }
    }
    vector<string> result;
    for (auto &word : A) {
      vector<int> v = getLetterVec(word);
      bool is_universal = true;
      for (int i = 0; i < 26; ++i) {
        if (v[i] < universal_vec[i]) {
          is_universal = false;
          break;
        }
      }
      if (is_universal) {
        result.push_back(word);
      }
    }
    return result;
  }

 private:
  vector<int> getLetterVec(const string &s) {
    vector<int> v(26, 0);
    for (char c : s) {
      ++v[c - 'a'];
    }
    return v;
  }
};
