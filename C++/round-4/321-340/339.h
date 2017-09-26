class Solution {
public:
    int depthSum(vector<NestedInteger> &nestedList) {
        int result = 0;
        helper(result, nestedList, 1);
        return result;
    }
    
private:
    void helper(int &result, const vector<NestedInteger> &nestedList, int level) {
        for (const NestedInteger &n : nestedList) {
            if (n.isInteger()) {
                result += level * n.getInteger();
            } else
                helper(result, n.getList(), level + 1);
        }
    }
};