class Solution {
 public:
  int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> result;
    unordered_set<int> last;
    for (int num : A) {
      unordered_set<int> curr;
      for (int prefix : last) {
        curr.insert((prefix | num));
      }
      curr.insert(num);
      result.insert(curr.begin(), curr.end());
      last = curr;
    }
    return result.size();
  }
};
