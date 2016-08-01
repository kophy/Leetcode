/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i)
            data.push(nestedList[i]);
        prepareStack(data);
    }

    int next() {
        int result = data.top().getInteger();
        data.pop();
        prepareStack(data);
        return result;
    }

    bool hasNext() {
        return !data.empty();
    }
private:
    stack<NestedInteger> data;

    void prepareStack(stack<NestedInteger> &data) {
        while (!data.empty() && !data.top().isInteger()) {
            NestedInteger temp = data.top();
            data.pop();
            vector<NestedInteger> children = temp.getList();
            for (int i = children.size() - 1; i >= 0; --i)
                data.push(children[i]);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */