class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums)
            ++count[num];
        
        // 1. degree of original array
        int degree = 0;
        for (auto &p : count)
            degree = max(degree, p.second);
        
        // 2. begin and end index of "supporting" values
        unordered_map<int, vector<int>> val2range;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (count[num] != degree)
                continue;
            if (!val2range.count(num))
                val2range[num] = vector<int>(2, i);
            else
                val2range[num][1] = i;
        }
        
        // 3. find best "supporting" value to minimize range
        int length = nums.size();
        for (auto &p : val2range)
            length = min(length, p.second[1] - p.second[0] + 1);
        return length;
    }
};