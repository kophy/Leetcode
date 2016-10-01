class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bull;
                secret[i] = '@', guess[i] = '#';
            }
        }
        map<char, int> count;
        for (int i = 0; i < secret.size(); ++i)
            ++count[secret[i]];
        for (int i = 0; i < guess.size(); ++i) {
            if (count.find(guess[i]) != count.end() && count[guess[i]] > 0) {
                ++cow;
                --count[guess[i]];
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};