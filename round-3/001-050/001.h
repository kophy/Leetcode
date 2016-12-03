class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val2idx;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (val2idx.count(target - num)) {
                vector<int> temp(2);
                temp[0] = val2idx[target - num];
                temp[1] = i;
                return temp;
            }
            val2idx[num] = i;
        }
        return vector<int>(2, -1);
    }
};