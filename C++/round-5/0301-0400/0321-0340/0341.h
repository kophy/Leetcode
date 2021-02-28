/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; --i) {
      if (!nestedList[i].isInteger() && nestedList[i].getList().empty()) {
        continue;
      }
      data.push(nestedList[i]);
    }
    cleanUp();
  }

  int next() {
    int x = data.top().getInteger();
    data.pop();
    cleanUp();
    return x;
  }

  bool hasNext() { return !data.empty(); }

 private:
  stack<NestedInteger> data;

  void cleanUp() {
    while (!data.empty() && !data.top().isInteger()) {
      auto l = data.top().getList();
      data.pop();
      for (int i = (int)l.size() - 1; i >= 0; --i) {
        data.push(l[i]);
      }
    }
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */