class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);
        for (int i = 0; i < magazine.size(); ++i)
            ++count[magazine[i] - 'a'];
        for (int i = 0; i < ransomNote.size(); ++i) {
            if (count[ransomNote[i] - 'a'])
                --count[ransomNote[i] - 'a'];
            else
                return false;
        }
        return true;
    }
};