/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
public:
    NestedInteger deserialize(string s) {
        function<bool(char)> isnumber = [](char c) {
            return (c == '-') || isdigit(c);
        };

        stack<NestedInteger> stk;
        stk.push(NestedInteger());

        for (auto it = s.begin(); it != s.end();) {
            const char & c = (*it);
            if (isnumber(c)) {
                auto it2 = find_if_not(it, s.end(), isnumber);
                int val = stoi(string(it, it2));
                stk.top().add(NestedInteger(val));
                it = it2;
            } else {
                if (c == '[') {
                    stk.push(NestedInteger());
                } else if (c == ']') {
                    NestedInteger ni = stk.top();
                    stk.pop();
                    stk.top().add(ni);
                }
                ++it;
            }
        }

        NestedInteger result = stk.top().getList().front();
        return result;
    }
};