class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> data;
        for (int i = (int)temperatures.size() - 1; i >= 0; --i) {
            while (!data.empty() && temperatures[data.top()] <= temperatures[i])
                data.pop();
            if (!data.empty())
                result[i] = data.top() - i;
            data.push(i);
        }
        return result;
    }
};