/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        stack<TreeNode *> path_p = getPath(root, p);
        stack<TreeNode *> path_q = getPath(root, q);
        TreeNode *result = nullptr;
        while (!path_p.empty() && !path_q.empty() && path_p.top() == path_q.top()) {
            result = path_p.top();
            path_p.pop();
            path_q.pop();
        }
        return result;
    }
private:
    stack<TreeNode *> getPath(TreeNode *root, TreeNode *target) {
        stack<TreeNode *> path;
        set<TreeNode *> visited;
        if (root)
            path.push(root);
        while (!path.empty()) {
            TreeNode *curr = path.top();
            if (curr == target)
                break;
            visited.insert(curr);
            if (curr->left && visited.find(curr->left) == visited.end())
                path.push(curr->left);
            else if (curr->right && visited.find(curr->right) == visited.end())
                path.push(curr->right);
            else
                path.pop();
        }
        stack<TreeNode *> result;
        while (!path.empty()) {
            result.push(path.top());
            path.pop();
        }
        return result;
    }
};