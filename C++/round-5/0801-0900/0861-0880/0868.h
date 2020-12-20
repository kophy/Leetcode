class Solution {
public:
  int binaryGap(int N) {
    bitset<32> b(N);
    vector<int> indices;
    for (int i = 0; i < 32; ++i) {
      if (b.test(i)) {
        indices.push_back(i);
      }
    }
    int max_distance = 0;
    for (int i = 0; i < (int)indices.size() - 1; ++i) {
      max_distance = max(max_distance, indices[i + 1] - indices[i]);
    }
    return max_distance;
  }
};
