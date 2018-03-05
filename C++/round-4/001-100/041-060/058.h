class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string temp, word;
        while (ss >> temp)
            word = temp;
        return word.size();
    }
};