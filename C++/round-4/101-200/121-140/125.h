class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0, j = (int)s.size() - 1;
		while (i < j) {
			while (i < j && !isalnum(s[i]))
				++i;
			while (i < j && !isalnum(s[j]))
				--j;
			if (i < j) {
				if (tolower(s[i++]) != tolower(s[j--]))
					return false;
			}
		}
		return true;
	}
};