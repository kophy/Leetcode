class NumArray {
public:
    NumArray(vector<int> &nums) {
        data = vector<int> (nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            data[i + 1] = data[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return data[j + 1] - data[i];
    }

private:
    vector<int> data;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);