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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> path_p, path_q;
        TreeNode *curr;

        curr = root;
        while (curr->val != p->val) {
            path_p.push(curr);
            if (curr->val < p->val)
                curr = curr->right;
            else
                curr = curr->left;
        }
        path_p.push(p);

        curr = root;
        while (curr->val != q->val) {
            path_q.push(curr);
            if (curr->val < q->val)
                curr = curr->right;
            else
                curr = curr->left;
        }
        path_q.push(q);

        curr = root;
        while (path_p.front() == path_q.front()) {
            curr = path_p.front();
            path_p.pop();
            path_q.pop();
        }
        return curr;
    }
};