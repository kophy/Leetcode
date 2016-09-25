class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        if (nums.size() == 0)
            return result;
        int begin = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > end + 1) {
                result.push_back(makeRange(begin, end));
                begin = nums[i];
            }
            end = nums[i];
        }
        result.push_back(makeRange(begin, end));
        return result;
    }

private:
    string makeRange(int begin, int end) {
        return (begin == end)? to_string(begin) : to_string(begin) + "->" + to_string(end);
    }
};