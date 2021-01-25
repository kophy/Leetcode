class Solution {
 public:
  vector<int> decode(vector<int>& encoded) {
    int x = 0;
    for (int i = 1; i <= encoded.size() + 1; ++i) {
      x ^= i;
      if (i < encoded.size() && i % 2 == 1) {
        x ^= encoded[i];
      }
    }

    vector<int> result = {x};
    for (int e : encoded) {
      result.push_back(result.back() ^ e);
    }
    return result;
  }
};