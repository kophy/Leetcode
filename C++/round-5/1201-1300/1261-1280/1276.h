class Solution {
public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    // 4x + 2y = tomato, x + y = cheese
    long temp = tomatoSlices - 2 * cheeseSlices;
    if (temp < 0 || temp % 2 == 1) {
      return {};
    }
    int jumbo = temp / 2;
    int small = cheeseSlices - jumbo;
    if (jumbo < 0 || small < 0) {
      return {};
    }
    return {jumbo, small};
  }
};