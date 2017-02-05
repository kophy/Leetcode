class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            ++count[c];
        string result = "";
        unordered_set<char> included;
        for (char c : s) {
            --count[c];
            if (included.count(c))
                continue;
            while (result.size() && result.back() > c && count[result.back()] > 0) {
                included.erase(result.back());
                result.pop_back();
            }
            result.push_back(c);
            included.insert(c);
        }
        return result;
    }
};