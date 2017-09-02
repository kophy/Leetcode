class Solution {
public:
    bool isValid(string s) {
        stack<char> data;
        unordered_map<char, char> match = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
		for (char c : s) {
			if (match.find(c) != match.end())
				data.push(match[c]);
			else {
				if (data.empty() || data.top() != c)
					return false;
				data.pop();
			}
		}
		return data.empty();
    }
};