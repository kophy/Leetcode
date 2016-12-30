class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] != guess[i])
                continue;
            ++bulls;
            secret[i] = '@';
            guess[i] = '#';
        }
        unordered_map<char, int> count;
        for (char c : secret)
            ++count[c];
        for (char c : guess)
            if (--count[c] >= 0)
                ++cows;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};