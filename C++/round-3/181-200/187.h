class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> count;
        for (int i = 0; i + 10 <= s.size(); ++i) {
            string temp = s.substr(i, 10);
            if (++count[temp] == 2)
                result.push_back(temp);
        }
        return result;
    }
};