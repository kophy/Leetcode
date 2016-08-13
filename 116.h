/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        vector<TreeLinkNode *> data;
        data.push_back(root);
        while (!data.empty()) {
            vector<TreeLinkNode *> temp;
            for (int i = 0; i < data.size(); ++i) {
                data[i]->next = (i + 1) < data.size()? data[i + 1] : nullptr;
                if (data[i]->left)
                    temp.push_back(data[i]->left);
                if (data[i]->right)
                    temp.push_back(data[i]->right);
            }
            data = temp;
        }
    }
};