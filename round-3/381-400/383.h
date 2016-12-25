class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;
for (char c : magazine)
            ++count[c];
for (char c : ransomNote) {
            if (count.find(c) == count.end() || count[c] <= 0)
                return false;
            --count[c];
        }
        return true;
    }
};