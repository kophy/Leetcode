class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    map<int, int> m;
    for (int x : arr1) {
      ++m[x];
    }
    int i = 0;
    for (int x : arr2) {
      int n = m[x];
      std::fill_n(arr1.begin() + i, n, x);
      i += n;
      m[x] = 0;
    }
    for (auto &p : m) {
      std::fill_n(arr1.begin() + i, p.second, p.first);
      i += p.second;
    }
    return arr1;
  }
};
