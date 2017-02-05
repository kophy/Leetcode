class Solution {
public:
    Solution(vector<int> nums) {
        data = nums;
    }

    int pick(int target) {
        int result = -1;
        int count = 0;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] != target)
                continue;
            ++count;
            if (rand() % count == 0)
                result = i;
        }
        return result;
    }

private:
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */