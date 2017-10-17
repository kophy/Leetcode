class Solution {
public:
    bool splitArray(vector<int>& nums) {
        // 1. length check
        if (nums.size() < 7)
            return false;
        int N = nums.size();
        
        // 2. build presum array
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; ++i)
            presum[i + 1] = presum[i] + nums[i];
        
        // 3. for each j, check equal splits of left and right parts
        for (int j = 3; j < N - 3; ++j) {
            unordered_set<int> left = helper(presum, 0, j - 1);
            unordered_set<int> right = helper(presum, j + 1, N - 1);
            for (int s : left)
                if (right.count(s))
                    return true;
        }
        return false;
    }
    
private:
    unordered_set<int> helper(vector<int> &presum, int begin, int end) {
        unordered_set<int> result;
        for (int i = begin + 1; i < end; ++i) {
            int s = presum[i] - presum[begin];
            int t = presum[end + 1] - presum[i + 1];
            if (s == t)
                result.insert(s);
        }
        return result;
    }
};