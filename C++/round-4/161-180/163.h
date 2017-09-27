class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if (nums.empty()) {
            result.push_back(makeRange(lower, upper));
            return result;
        }
        
        int N = nums.size();
        if (nums[0] > lower)
            result.push_back(makeRange(lower, nums[0] - 1));
        
        int i = 1;
        while (i < N) {
            // missing range is always between two adjacent elements
            if (nums[i] > nums[i - 1] + 1)
                result.push_back(makeRange(nums[i - 1] + 1, nums[i] - 1));
            ++i;
            while (i < nums.size() && nums[i] == nums[i - 1])
                ++i;
        }
        
        if (nums[N - 1] < upper)
            result.push_back(makeRange(nums[N - 1] + 1, upper));
        return result;
    }
    
private:
    string makeRange(int s, int e) {
        if (s == e)
            return to_string(s);
        return to_string(s) + "->" + to_string(e);
    }
};