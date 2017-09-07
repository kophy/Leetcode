class Solution {
public:
	string decodeString(string s) {
		stack<string> str_stk;
		stack<int> cnt_stk;

		string result = "";
		int times = 0;

		// classic on-the-fly processing pattern
		for (char c : s) {
			if (isdigit(c)) {
				times = times * 10 + (c - '0');
			} else if (isalpha(c)) {
				if (str_stk.empty())
					result += c;
				else
					str_stk.top() += c;
			} else if (c == '[') {
				cnt_stk.push(times);
				times = 0;
				str_stk.push("");
			} else {
				string temp = "";
				for (int i = 0; i < cnt_stk.top(); ++i)
					temp += str_stk.top();
				cnt_stk.pop();
				str_stk.pop();
				if (str_stk.empty())
					result += temp;
				else
					str_stk.top() += temp;
			}
		}
		return result;
	}
};