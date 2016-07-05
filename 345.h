class Solution {
public:
    string reverseVowels(string s) {
        vector<int> index;
        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i]))
                index.push_back(i);
        }
        for (int i = 0; i < index.size() / 2; ++i) {
            char temp = s[index[i]];
            s[index[i]] = s[index[index.size() - i - 1]];
            s[index[index.size() - i - 1]] = temp;
        }
        return s;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u');
    }
};