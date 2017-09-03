class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> count;
        for (int i = 0; i < s.size(); ++i)
            ++count[s[i] - 'a'];
        for (int i = 0; i < s.size(); ++i)
            if (count[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};