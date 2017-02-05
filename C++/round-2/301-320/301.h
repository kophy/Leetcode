class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        queue<string> data;
        unordered_set<string> visited;

        data.push(s);
        visited.insert(s);

        // BFS: remove one character at a time
        while (!data.empty()) {
            string curr = data.front();
            data.pop();
            // case 1: not minimal
            if (result.size() && result[0].size() > curr.size())
                continue;
            // case 2: valid, no need to search shorter string
            if (valid(curr)) {
                if (result.empty() || result[0].size() == curr.size())
                    result.push_back(curr);
                continue;
            }
            // case 3: search shorter string
            for (int i = 0; i < curr.size(); ++i) {
                if (curr[i] == '(' || curr[i] == ')') {
                    string temp = curr;
                    temp.erase(temp.begin() + i);
                    if (visited.find(temp) != visited.end())
                        continue;
                    data.push(temp);
                    visited.insert(temp);
                }
            }
        }
        return result;
    }

private:
    bool valid(string &s) {
        int counter = 0;
for (auto c : s) {
            if (c == '(')
                ++counter;
            else if (c == ')') {
                if (counter > 0)
                    --counter;
                else
                    return false;
            }
        }
        return counter == 0;
    }
};