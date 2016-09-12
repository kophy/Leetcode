class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		hash<string> DNA_hash;
        map<int, int> count;
        for (int i = 0; i + 10 <= s.length(); ++i) {
            string temp = s.substr(i, 10);
            if (++count[DNA_hash(temp)] == 2)
                result.push_back(temp);
        }
        return result;
    }
};