/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            data.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !data.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *temp = data.top();
        data.pop();
        int val = temp->val;
        temp = temp->right;
        while (temp) {
            data.push(temp);
            temp = temp->left;
        }
        return val;
    }

private:
    stack<TreeNode *> data;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */