class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        for (int i = 0; i < s.size(); ) {
            int j = i, k = i;
			
			/*  skip same characters, avoid cases like:
				aaaaaaaaaaaaa…aaa
			*/
            while (k + 1 < s.size() && s[k + 1] == s[i])
                ++k;
            i = k + 1;
            
			while (j - 1 >= 0 && k + 1 < s.size() && s[j - 1] == s[k + 1]) {
                --j;
                ++k;
            }
            string curr = s.substr(j, k - j + 1);
            if (curr.size() > result.size())
                result = curr;
        }
        return result;
    }
};