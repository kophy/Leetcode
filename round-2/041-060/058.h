class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        stringstream ss(s);
        string word;
        ss >> word;
        return word.size();
    }
};