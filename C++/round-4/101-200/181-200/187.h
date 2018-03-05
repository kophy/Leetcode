class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		unordered_map<string, int> count;
		for (int i = 0; i + 10 <= s.size(); ++i) {
			string dna = s.substr(i, 10);
			if (++count[dna] == 2)
				result.push_back(dna);
		}
		return result;
	}
};