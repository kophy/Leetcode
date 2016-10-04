cclass Solution {
public:
    int longestPalindrome(string s) {
        map<int, int> count;
        for (char c : s)
            ++count[c];
        int even = 0, odd = 0, center = 0;
        for (auto iter = count.begin(); iter != count.end(); ++iter) {
            if (iter->second % 2 == 0)
                even += iter->second;
            else {
                odd += iter->second - 1;
                center = 1;
            }
        }
        return even + odd + center;
    }
};