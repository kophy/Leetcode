class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> dictionary) {
		for (string word : dictionary) {
			if (used.find(word) == used.end()) {
				++abbr_count[create_abbr(word)];
				used.insert(word);
			}
		}
	}

	bool isUnique(string word) {
		string abbr = create_abbr(word);
		if (used.find(word) != used.end())
			return abbr_count[abbr] == 1;
		else
			return abbr_count.find(abbr) == abbr_count.end();
	}

private:
	unordered_set<string> used;
	unordered_map<string, int> abbr_count;

	string create_abbr(string & s) {
		if (s.size() <= 2)
			return s;
		else
			return string(1, s[0]) + to_string(s.size() - 2) + string(1, s.back());
	}
};