class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        map<string, int> count;
        for (int i = 0; i + 10 <= s.length(); ++i) {
            string curr = s.substr(i, 10);
            ++count[curr];
            if (count[curr] == 2)
                result.push_back(curr);
        }
        return result;
    }
};