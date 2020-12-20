class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int boats = 0;
    int i = 0, j = (int)people.size() - 1;
    while (i < j) {
      if (people[i] + people[j] <= limit) {
        ++i;
      }
      --j;
      ++boats;
    }
    // check if there is one person left.
    if (i == j) {
      ++boats;
    }
    return boats;
  }
};
