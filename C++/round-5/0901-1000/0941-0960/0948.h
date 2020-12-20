class Solution {
public:
  int bagOfTokensScore(vector<int> &tokens, int P) {
    sort(tokens.begin(), tokens.end());
    int points = 0, max_points = 0;
    int i = 0, j = (int)tokens.size() - 1;
    while (i <= j) {
      if (P >= tokens[i]) {
        P -= tokens[i];
        ++points;
        max_points = max(max_points, points);
        ++i;
      } else {
        if (points > 0) {
          --points;
          P += tokens[j];
          --j;
        } else {
          break;
        }
      }
    }
    return max_points;
  }
};
