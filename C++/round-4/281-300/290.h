class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> words = parseWords(str);
		if (pattern.size() != words.size())
			return false;

		unordered_map<char, string> char2word;
		unordered_set<string> used_words;

		for (int i = 0; i < pattern.size(); ++i) {
			char c = pattern[i];
			string &word = words[i];
			if (char2word.count(c)) {
				if (char2word[c] != word)
					return false;
			} else {
				if (used_words.count(word))
					return false;
				char2word[c] = word;
				used_words.insert(word);
			}
		}
		return true;
	}

private:
	vector<string> parseWords(const string &str) {
		stringstream ss(str);
		string temp;
		vector<string> words;
		while (ss >> temp)
			words.push_back(temp);
		return words;
	}
};