class NumArray {
public:
    NumArray(vector<int> &nums) {
        sum.push_back(0);
        for (int i = 0; i < nums.size(); ++i)
            sum.push_back(sum[i] + nums[i]);
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
private:
    vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);