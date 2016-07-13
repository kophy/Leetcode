class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operand;
        for (int i = 0; i < tokens.size(); ++i) {
            if (isdigit(tokens[i][0]) || tokens[i].size() > 1)
                operand.push(atoi(tokens[i].c_str()));
            else {
                int n2 = operand.top();
                operand.pop();
                int n1 = operand.top();
                operand.pop();
                if (tokens[i] == "+")
                    operand.push(n1 + n2);
                else if (tokens[i] == "-")
                    operand.push(n1 - n2);
                else if (tokens[i] == "*")
                    operand.push(n1 * n2);
                else
                    operand.push(n1 / n2);
            }
        }
        return operand.top();
    }
};