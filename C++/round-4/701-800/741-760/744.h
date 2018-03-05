class Solution {
 public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    auto distance = [](char c, char target) -> int {
      return (c > target) ? c - target : c + 26 - target;
    };
    return *min_element(letters.begin(), letters.end(),
                        [&target, &distance](char &a, char &b) -> bool {
                          return distance(a, target) < distance(b, target);
                        });
  }
};
