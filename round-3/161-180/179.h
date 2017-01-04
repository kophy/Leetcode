class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> data;
        for (int num : nums)
            data.push_back(to_string(num));
        sort(data.begin(), data.end(), [](string &s1, string &s2)->bool {
            return s1 + s2 > s2 + s1;
        });
        string result;
        for (string s : data)
            result += s;
        int i = 0;
        while (i < result.size() && result[i] == '0')
            ++i;
        return (i == result.size())? "0" : result.substr(i);
    }
};