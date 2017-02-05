class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        queue<string> data;
        data.push(s);
        unordered_set<string> visited;
        visited.insert(s);
        while (!data.empty()) {
            string curr = data.front();
            data.pop();
            if (!result.empty() && result[0].size() > curr.size())
                break;
            if (isValid(curr))
                result.push_back(curr);
            else {
                for (int i = 0; i < curr.size(); ++i) {
                    if (curr[i] != '(' && curr[i] != ')')
                        continue;
                    string temp = curr;
                    temp.erase(temp.begin() + i);
                    if (visited.count(temp))
                        continue;
                    data.push(temp);
                    visited.insert(temp);
                }
            }
        }
        return result;
    }

private:
    bool isValid(string &s) {
        int unclosed = 0;
for (char c: s) {
            if (c == '(')
                ++unclosed;
            else if (c == ')') {
                if (--unclosed < 0)
                    return false;
            }
        }
        return unclosed == 0;
    }
};