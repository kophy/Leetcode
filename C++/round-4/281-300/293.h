class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        for (int i = 0; i < (int)s.size() - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string temp = s;
                temp[i] = temp[i + 1] = '-';
                result.push_back(temp);
            }
        }
        return result;
    }
};