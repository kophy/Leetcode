class Solution {
public:
    string breakPalindrome(string palindrome) {
        int N = palindrome.size();
        for (int i = 0; i < N / 2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[N - 1] = 'b';
        return N <= 1? "" : palindrome;
    }
};