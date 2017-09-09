class Solution {
public:
	int maxProduct(vector<string>& words) {
		vector<bitset<26>> masks;
	for (string &word : words)
			masks.push_back(makeWordMask(word));

		int result = 0;
		for (int i = 0; i < words.size(); ++i) {
			for (int j = i + 1; j < words.size(); ++j) {
				if ((masks[i] & masks[j]) != 0)
					continue;
				result = max(result, (int)words[i].size() * (int)words[j].size());
			}
		}
		return result;
	}

private:
	bitset<26> makeWordMask(string &word) {
		bitset<26> mask(0);
	for (char c  : word)
			mask.set(c - 'a');
		return mask;
	}
};