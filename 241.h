class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i = 0; i < input.size(); ++i) {
            if(ispunct(input[i])) {
				for(int a : diffWaysToCompute(input.substr(0, i))) {
					for(int b : diffWaysToCompute(input.substr(i + 1))) {
                        if(input[i] == '+')
                            result.push_back(a + b);
                        else if(input[i] == '-')
                            result.push_back(a-b);
                        else if(input[i] == '*')
                            result.push_back(a*b);
                    }
                }
            }
        }
        if (result.empty())
            result.push_back(stoi(input));
        return result;
    }
};