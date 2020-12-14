/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        helper(root, 0);
    }
    
    bool find(int target) {
        return elements.count(target);
    }
    
private:
    unordered_set<int> elements;
    
    void helper(TreeNode *root, int value) {
        if (root == nullptr) {
            return;
        }
        elements.insert(value);
        helper(root->left, value * 2 + 1);
        helper(root->right, value * 2 + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */