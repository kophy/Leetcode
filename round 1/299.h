class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        for (int i = 0; i < min(secret.size(), guess.size()); ++i) {
            if (secret[i] == guess[i]) {
                ++bull;
                secret[i] = '#';
                guess[i] = '@';
            }
        }
        map<char, int> count;
        for (int i = 0; i < secret.size(); ++i)
            ++count[secret[i]];
        for (int j = 0; j < guess.size(); ++j) {
            if (count[guess[j]] > 0) {
                ++cow;
                --count[guess[j]];
            }
        }
        return (int2str(bull) + "A" + int2str(cow) + "B");
    }
private:
    string int2str(int d) {
        stringstream ss;
        ss << d;
        return ss.str();
    }
};