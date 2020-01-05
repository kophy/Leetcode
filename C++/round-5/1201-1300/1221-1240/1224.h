class Solution {
 public:
  int maxEqualFreq(vector<int> &nums) {
    unordered_map<int, int> count;
    map<int, int> freq;

    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int previous_count = count[nums[i]];
      ++count[nums[i]];
      if (freq.find(previous_count) != freq.end()) {
        --freq[previous_count];
        if (freq[previous_count] == 0) {
          freq.erase(previous_count);
        }
      }
      ++freq[count[nums[i]]];
      if (isValidFreq(count, freq)) {
        result = max(result, i + 1);
      }
    }
    return result;
  }

 private:
  bool isValidFreq(const unordered_map<int, int> &count,
                   const map<int, int> &freq) {
    if (freq.size() == 1) {
      if (count.size() == 1) {
        // There is only one number appearing multiple times.
        return true;
      } else {
        // There are multiple numbers each appearing once.
        if (freq.begin()->first == 1) {
          return true;
        }
      }
    }
    if (freq.size() == 2) {
      if (freq.begin()->first == 1 && freq.begin()->second == 1) {
        // Delete the number that only appears once.
        return true;
      }
      if (freq.rbegin()->first == freq.begin()->first + 1 &&
          freq.rbegin()->second == 1) {
        // Delete the number that appear once more than others.
        return true;
      }
    }
    return false;
  }
};