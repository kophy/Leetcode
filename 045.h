class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, start = 0, end = 0;
        while (end < nums.size() - 1) {
            ++step;
            int next_start = end + 1;
            int next_end = INT_MIN;
            for (int i = start; i <= end; i++) {
                if (i + nums[i] >= nums.size() - 1)
                    return step;
                next_end = max(next_end, i + nums[i]);
            }
            start = next_start;
            end = next_end;
        }
        return step;
    }
};