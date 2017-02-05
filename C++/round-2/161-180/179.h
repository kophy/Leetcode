class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> data;
        for (int i = 0; i < nums.size(); ++i)
            data.push_back(to_string(nums[i]));

        /* sort numbers as prefix in descending order */
        sort(data.begin(), data.end(), [](const string &sa, const string &sb)->bool {
            return sa + sb > sb + sa;
        });
        string result = "";
        for (int i = 0; i < data.size(); ++i)
            result += data[i];
        if (result.size() == 0 || result[0] == '0')
            result = "0";
        return result;
    }
};