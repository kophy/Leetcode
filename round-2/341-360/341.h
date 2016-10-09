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
        for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); ++iter)
            data.push(*iter);
        prepare_stack();
    }

    int next() {
        int result = data.top().getInteger();
        data.pop();
        prepare_stack();
        return result;
    }

    bool hasNext() {
        return !data.empty();
    }

private:
    stack<NestedInteger> data;

    void prepare_stack(void) {
        while (!data.empty() && !data.top().isInteger()) {
            auto temp = data.top().getList();
            data.pop();
            for (auto iter = temp.rbegin(); iter != temp.rend(); ++iter)
                data.push(*iter);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */