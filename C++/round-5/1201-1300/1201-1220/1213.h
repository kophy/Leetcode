class Solution {
public:
  vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2,
                                 vector<int> &arr3) {
    vector<int> result;
    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
      if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
        result.push_back(arr1[i]);
        ++i;
        ++j;
        ++k;
      } else if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
        ++i;
      } else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) {
        ++j;
      } else {
        ++k;
      }
    }
    return result;
  }
};