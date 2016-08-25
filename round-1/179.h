class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result = "";
        if (nums.size() == 0)
            return result;
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            string sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa;
        });
        for (int i = 0; i < nums.size(); ++i)
            result += to_string(nums[i]);
        if (result[0] == '0')
            result = "0";
        return result;
    }
};