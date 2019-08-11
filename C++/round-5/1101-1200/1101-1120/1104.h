class Solution {
 public:
  vector<int> pathInZigZagTree(int label) {
    vector<int> path;
    if (getHeight(label) % 2 == 0) {
      label = getMirror(label);
    }
    for (; label != 0; label /= 2) {
      path.push_back(label);
    }
    std::reverse(path.begin(), path.end());
    for (int i = 1; i < path.size(); i += 2) {
      path[i] = getMirror(path[i]);
    }
    return path;
  }

 private:
  int getHeight(int n) {
    int h = 0;
    while ((1 << h) <= n) {
      ++h;
    }
    return h;
  }

  int getMirror(int n) {
    int h = getHeight(n);
    return (1 << (h - 1)) + (1 << h) - n - 1;
  }
};
