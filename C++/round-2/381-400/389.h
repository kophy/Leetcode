class Solution {
public:
    char findTheDifference(string s, string t) {
        int d = accumulate(t.begin(), t.end(), 0) - accumulate(s.begin(), s.end(), 0);
        return (char)d;
    }
};