class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            ++count[c];
        int result = 0;
        bool odd = false;
        for (auto iter = count.begin(); iter != count.end(); ++iter) {
            result += iter->second;
            if (iter->second % 2 == 1) {
                --result;
                odd = true;
            }
        }
        result += odd? 1 : 0;
        return result;
    }
};