class Solution {
public:
	NestedInteger deserialize(string s) {
		stack<NestedInteger> data;

		// same as processing "[s]", avoid stack empty case
		data.push(NestedInteger());

		int i = 0;
		while (i < s.size()) {
			char c = s[i];

			// case 1: number
			if (c == '-' || isdigit(c)) {
				int len = 1;
				while (i + len < s.size() && isdigit(s[i + len]))
					++len;
				data.top().add(NestedInteger(stoi(s.substr(i, len))));
				i += len;
			}
			// case 2: '[' and ']'
			else {
				if (c == '[') {
					data.push(NestedInteger());
				} else if (c == ']') {
					auto ni = data.top();
					data.pop();
					data.top().add(ni);
				}
				++i;
			}
		}

		NestedInteger result = data.top().getList()[0];
		return result;
	}
};