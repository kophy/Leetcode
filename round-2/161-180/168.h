class Solution {
public:
    string convertToTitle(int n) {
        string title = "";
        while (n) {
            --n;
            title.push_back('A' + n % 26);
            n /= 26;
        }
        reverse(title.begin(), title.end());
        return title;
    }
};