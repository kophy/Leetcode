class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> data;
        for (int i = 0; i < tokens.size(); ++i) {
            if (isdigit(tokens[i][0]) || tokens[i].size() > 1) {	// tokens[i] = "-1" is a number!
                int temp = stoi(tokens[i]);
                data.push(temp);
            } else {
                int n2 = data.top();
                data.pop();
                int n1 = data.top();
                data.pop();
                char op = tokens[i][0];

                /* calculate immediately since all operands are known */
                if (op == '+')
                    data.push(n1 + n2);
                else if (op == '-')
                    data.push(n1 - n2);
                else if (op == '*')
                    data.push(n1 * n2);
                else
                    data.push(n1 / n2);
            }
        }
        return data.top();
    }
};