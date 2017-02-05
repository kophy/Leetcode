class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() <= k)
            return "0";
        int keep = num.size() - k;
        string result = "";
        for (char c : num) {
            while (result.size() && result.back() > c && k > 0) {
                --k;
                result.pop_back();
            }
            result.push_back(c);
        }
        result.resize(keep);
        int pos = 0;
        while (pos < result.size() && result[pos] == '0')
            ++pos;
        return (pos == result.size())? "0" : result.substr(pos);
    }
};