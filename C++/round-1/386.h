class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        stack<int> stk;
        stk.push(1);
        while(!stk.empty()) {
            int num = stk.top();
            result.push_back(num);
            stk.pop();
			
            if(num + 1 <= n && num % 10 < 9)
                stk.push(num + 1);
            if(10 * num <= n)
                stk.push(10 * num);
        }
        return result;
    }
};