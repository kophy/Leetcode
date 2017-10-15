class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> data;
        if (root)
            data.push(root);
        while (!data.empty()) {
            queue<TreeLinkNode *> next;
            TreeLinkNode *last = nullptr;
            while (!data.empty()) {
                TreeLinkNode *curr = data.front();
                data.pop();
                if (curr->left)
                    next.push(curr->left);
                if (curr->right)
                    next.push(curr->right);
                if (last)
                    last->next = curr;
                last = curr;
            }
            data = next;
        }
    }
};