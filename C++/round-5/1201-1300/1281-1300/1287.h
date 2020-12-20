class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    int N = arr.size();
    int last = arr[0], count = 0;
    for (int i = 0; i < arr.size(); ++i) {
      if (arr[i] == last) {
        ++count;
        if (count * 4 > N) {
          return arr[i];
        }
      } else {
        last = arr[i];
        count = 1;
      }
    }
    return arr[last];
  }
};