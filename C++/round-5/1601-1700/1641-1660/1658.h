// 1. BFS
struct State {
  int left_;
  int right_;
  int x_;

  State(int left, int right, int x) {
    left_ = left;
    right_ = right;
    x_ = x;
  }
};

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    queue<State> data;
    data.push(State(0, (int)nums.size() - 1, x));

    int step = 0;
    while (!data.empty()) {
      ++step;
      queue<State> next;
      while (!data.empty()) {
        State s = data.front();
        data.pop();

        if (s.left_ < s.right_) {
          if (s.x_ == nums[s.left_] || s.x_ == nums[s.right_]) {
            return step;
          }
          next.push(State(s.left_ + 1, s.right_, s.x_ - nums[s.left_]));
          next.push(State(s.left_, s.right_ - 1, s.x_ - nums[s.right_]));
        } else if (s.left_ == s.right_) {
          if (s.x_ == nums[s.left_]) {
            return step;
          }
        }
      }
      data = std::move(next);
    }
    return -1;
  }
};

// 2. Prefix and suffix sum.
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    unordered_map<int, int> suffix_sum_to_index;
    int suffix_sum = 0;
    suffix_sum_to_index[0] = nums.size();
    for (int i = (int)nums.size() - 1; i >= 0; --i) {
      suffix_sum += nums[i];
      suffix_sum_to_index[suffix_sum] = i;
    }

    int prefix_sum = 0;
    int result = INT_MAX;
    if (suffix_sum_to_index.count(x)) {
      result = nums.size() - suffix_sum_to_index[x];
    }

    for (int i = 0; i < nums.size(); ++i) {
      prefix_sum += nums[i];
      int rest = x - prefix_sum;
      if (suffix_sum_to_index.count(rest) && suffix_sum_to_index[rest] > i) {
        result =
            min(result, i + ((int)nums.size() - suffix_sum_to_index[rest]) + 1);
      }
    }
    return result == INT_MAX ? -1 : result;
  }
};