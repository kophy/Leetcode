class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (result.find(input) != result.end())
            return result[input];
        vector<int> temp;
        for (int i = 0; i < input.size(); ++i) {
            if (ispunct(input[i])) {
                char op = input[i];
                vector<int> left  = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); ++j)
                    for (int k = 0; k < right.size(); ++k)
                        temp.push_back(calculate(op, left[j], right[k]));
            }
        }

        /* the whole string is a number */
        if (input.size() && temp.empty())
            temp.push_back(stoi(input));

        result[input] = temp;	// store answers for sub-problems
        return temp;
    }

private:
    map<string, vector<int>> result;

    int calculate(char op, int left, int right) {
        if (op == '+')
            return left + right;
        else if (op == '-')
            return left - right;
        else
            return left * right;
    }
};