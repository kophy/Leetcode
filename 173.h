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
        return (!data.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *result = NULL;
        if (!data.empty()) {
            result = data.top();
            data.pop();
            TreeNode *curr = result->right;
            while (curr) {
                data.push(curr);
                curr = curr->left;
            }
        }
        return result->val;
    }
private:
    stack<TreeNode *> data;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */