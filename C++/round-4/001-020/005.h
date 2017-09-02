class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        
        for (int i = 0; i < s.size(); ) {
            int j = i, k = i;

            // skip consecutive same character
            while (k + 1 < s.size() && s[k + 1] == s[i])
                ++k;
            
            // next i will be the first different character
            i = k + 1;
            
            // grow towards two sides
			while (j - 1 >= 0 && k + 1 < s.size() && s[j - 1] == s[k + 1]) {
                --j;
                ++k;
            }
            result = (result.size() >= k - j + 1)? result : s.substr(j, k - j + 1);
        }
        return result;
    }
};