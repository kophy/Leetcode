class Solution {
 public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> result(num_people, 0);
    int i = 0;
    while (i + 1 <= candies) {
      result[i % num_people] += i + 1;
      candies -= (i + 1);
      ++i;
    }
    result[i % num_people] += candies;
    return result;
  }
};
