class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i)
            result = say(result);
        return result;
    }

private:
    string say(string s) {
        string result = "";
        int pos = 0;
        while (pos < s.size()) {
            int count = 0;
            while (pos + count < s.size() && s[pos + count] == s[pos])
                ++count;

            result += to_string(count) + s[pos];	// to_string converts int to string

            pos += count;
        }
        return result;
    }
};