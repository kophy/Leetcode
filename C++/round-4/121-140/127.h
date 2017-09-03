class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		queue<string> data;
		vector<bool> used(wordList.size(), false);
		data.push(beginWord);

		int step = 0;
		while (!data.empty()) {
			++step;
			queue<string> next;
			while (!data.empty()) {
				string word = data.front();
				data.pop();
				for (int i = 0; i < wordList.size(); ++i) {
					if (used[i] || distance(word, wordList[i]) != 1)
						continue;
					if (wordList[i] == endWord)
						return step + 1;
					next.push(wordList[i]);
					used[i] = true;
				}
			}
			data = next;
		}
		return 0;
	}

private:
	int distance(string &s, string &t) {
		int diff = 0;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] != t[i])
				++diff;
		return diff;
	}
};