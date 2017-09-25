class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> data;
        for (string &token : tokens) {
            if (token.size() > 1 || isdigit(token[0]))
                data.push(stoi(token));
            else {
                int n2 = data.top();
                data.pop();
                int n1 = data.top();
                data.pop();
                
                switch (token[0]) {
                    case '+':
                        data.push(n1 + n2);
                        break;
                    case '-':
                        data.push(n1 - n2);
                        break;
                    case '*':
                        data.push(n1 * n2);
                        break;
                    default:
                        data.push(n1 / n2);
                        break;
                }
            }
        }
        return data.top();
    }
};