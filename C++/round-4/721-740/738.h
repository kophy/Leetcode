class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int pivot = s.size();
        
        // find leftmost reversed pair (check->adjust->check on adjusted)
        for (int i = (int)s.size() - 1; i > 0; --i) {
            if (s[i - 1] > s[i]) {
                pivot = i;
                s[i - 1] -= 1;
            }
        }
        fill(s.begin() + pivot, s.end(), '9');
        return stoi(s);
    }
};