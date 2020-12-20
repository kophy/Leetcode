class Solution {
public:
  vector<int> transformArray(vector<int> &arr) {
    while (true) {
      vector<int> transformed = transform(arr);
      if (transformed == arr) {
        return transformed;
      }
      arr = transformed;
    }
    return {};
  }

private:
  vector<int> transform(const vector<int> &arr) {
    vector<int> transformed = arr;
    for (int i = 1; i < (int)arr.size() - 1; ++i) {
      if (arr[i] < min(arr[i - 1], arr[i + 1])) {
        ++transformed[i];
      }
      if (arr[i] > max(arr[i - 1], arr[i + 1])) {
        --transformed[i];
      }
    }
    return transformed;
  }
};