class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        sort(nums.begin(), nums.end());

        int begin = 0, end = 0;
        while (begin < nums.size()) {
            if (end + 1 < nums.size() && nums[end + 1] == nums[end] + 1)
                ++end;
            else {
                string temp;
                if (end > begin)
                    temp = int2str(nums[begin]) + "->" + int2str(nums[end]);
                else
                    temp = int2str(nums[begin]);
                result.push_back(temp);
                begin = end + 1;
                end = begin;
            }
        }
        return result;
    }

private:
    string int2str(int d) {
        stringstream ss;
        ss << d;
        return ss.str();
    }
};