class Solution {
public:
	string reverseVowels(string s) {
		int i = 0, j = (int)s.size() - 1;
		while (i < j) {
			while (i < j && !isVowel(tolower(s[i])))
				++i;
			while (i < j && !isVowel(tolower(s[j])))
				--j;
			swap(s[i++], s[j--]);
		}
		return s;
	}

private:
	bool isVowel(char c) {
		unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
		return vowels.count(c);
	}
};