class Solution {
 public:
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> result(seq.size(), 0);
    int depth = 0;
    for (int i = 0; i < seq.size(); ++i) {
      if (seq[i] == '(') {
        ++depth;
      }
      if (depth % 2 == 0) {
        result[i] = 1;
      }
      if (seq[i] == ')') {
        --depth;
      }
    }
    return result;
  }
};
