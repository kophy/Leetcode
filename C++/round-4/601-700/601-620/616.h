class Solution {
public:
	string addBoldTag(string s, vector<string> &dict) {
		vector<bool> bold(s.size(), false);
		for (int i = 0; i < s.size(); ++i) {
		for (string &word : dict) {
				if (i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
					for (int j = 0; j < word.size(); ++j)
						bold[i + j] = true;
				}
			}
		}
		string result = "";
		bool is_bold = false;
		for (int i = 0; i < s.size(); ++i) {
			if (!is_bold && bold[i]) {
				result += "<b>";
				is_bold = true;
			} else if (is_bold && !bold[i]) {
				result += "</b>";
				is_bold = false;
			}
			result += s[i];
		}
		if (is_bold)
			result += "</b>";
		return result;
	}
};