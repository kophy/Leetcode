class SparseVector {
 public:
  SparseVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      data_[i] = nums[i];
    }
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int result = 0;
    for (const auto& [i, _] : data_) {
      if (!vec.data_.count(i)) {
        continue;
      }
      result += data_[i] * vec.data_[i];
    }
    return result;
  }

 private:
  unordered_map<int, int> data_;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);