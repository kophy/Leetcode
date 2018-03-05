class Solution {
public:
	bool validPalindrome(string s) {
		int i = 0, j = (int)s.size() - 1;
		for (; i < j; ++i, --j)
			if (s[i] != s[j])
				break;

		// case 1: already palindrome
		if (i == j)
			return true;
		// case 2: delete one character from left or right
		else
			return isPalindrome(s.substr(0, i) + s.substr(i + 1)) || isPalindrome(s.substr(0, j) + s.substr(j + 1));
	}

private:
	bool isPalindrome(string s) {
		for (int i = 0, j = (int)s.size() - 1; i < j; ++i, --j)
			if (s[i] != s[j])
				return false;
		return true;
	}
};