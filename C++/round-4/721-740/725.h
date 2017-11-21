class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int N = length(root), R = N % k;
        vector<ListNode *> result;
        for (int i = 0; i < k; ++i) {
            // calculate length of i-th linked list part
            int len = N / k;
            if (R > 0) {
                len = len + 1;
                --R;
            }
            
            // get i-th linked list part
            ListNode temp(0), *curr = &temp;
            for (int j = 0; j < len; ++j) {
                ListNode *rest = root->next;
                root->next = nullptr;
                curr->next = root;
                curr = curr->next;
                root = rest;
            }
            result.push_back(temp.next);
        }
        return result;
    }
    
private:
    int length(ListNode *root) {
        return root? 1 + length(root->next) : 0;
    }
};