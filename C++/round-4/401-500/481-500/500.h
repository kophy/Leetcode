class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
		unordered_map<char, int> key2row;
		for (int i = 0; i < keyboard.size(); ++i)
			for (char key : keyboard[i])
				key2row[key] = i;

		vector<string> result;
		for (string &word : words) {
			bool same = true;
			for (int i = 1; i < word.size(); ++i)
				if (key2row[tolower(word[i])] != key2row[tolower(word[0])]) {
					same = false;
					break;
				}
			if (same)
				result.push_back(word);
		}
		return result;
	}
};