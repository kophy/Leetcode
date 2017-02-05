class Solution {
public:
    string decodeString(string s) {
        stack<string> pattern;
        stack<int> repeat;

        string result = "";
        int count = 0;
for (char d : s) {
            if (isdigit(d))
                count = count * 10 + (d - '0');
            else if (isalpha(d))
                pattern.empty()? result.push_back(d) : pattern.top().push_back(d);
            else if (d == '[') {
                repeat.push(count);
                count = 0;
                pattern.push("");
            } else if (d == ']') {
                string p = pattern.top();
                pattern.pop();
                int r = repeat.top();
                repeat.pop();
                string temp = "";
                for (int j = 0; j < r; ++j)
                    temp += p;
                pattern.empty()? result += temp : pattern.top() += temp;
            }
        }
        return result;
    }
};