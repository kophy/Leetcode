class NumArray {
 public:
  NumArray(vector<int>& nums) {
    presums.push_back(0);
    for (int x : nums) {
      presums.push_back(presums.back() + x);
    }
  }

  int sumRange(int i, int j) { return presums[j + 1] - presums[i]; }

 private:
  vector<int> presums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */