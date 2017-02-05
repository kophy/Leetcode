class NumArray {
public:
    NumArray(vector<int> &nums) {
        root = buildTree(nums, 0, (int)nums.size() - 1);
    }

    void update(int i, int val) {
        updateTree(root, i, val);
    }

    int sumRange(int i, int j) {
        return sumTreeRange(root, i, j);
    }

private:
    typedef struct SegTreeNode {
        int start, end;
        int sum;
        SegTreeNode *left, *right;

        SegTreeNode(int s, int e) {
            start = s, end = e;
            sum = 0;
            left = NULL, right = NULL;
        }
    } SegTreeNode;

    SegTreeNode *root;

    void updateSum(SegTreeNode *curr) {
        curr->sum = 0;
        if (curr->left)
            curr->sum += curr->left->sum;
        if (curr->right)
            curr->sum += curr->right->sum;
    }

    SegTreeNode *buildTree(vector<int> &data, int start, int end) {
        if (start > end)
            return NULL;
        SegTreeNode *curr = new SegTreeNode(start, end);
        if (start == end) {
            curr->sum = data[start];
        } else {
            int mid = (start + end) / 2;
            curr->left = buildTree(data, start, mid);
            curr->right = buildTree(data, mid + 1, end);
            curr->sum = 0;
            updateSum(curr);
        }
        return curr;
    }

    void updateTree(SegTreeNode *curr, int pos, int val) {
        if (curr->start == curr->end) {
            curr->sum = val;
            return;
        }
        int mid = (curr->start + curr->end) / 2;
        if (pos <= mid)
            updateTree(curr->left, pos, val);
        else
            updateTree(curr->right, pos, val);
        curr->sum = 0;
        updateSum(curr);
    }

    int sumTreeRange(SegTreeNode *curr, int start, int end) {
        if (curr == NULL || start > end)
            return 0;
        if (curr->start == start && curr->end == end)
            return curr->sum;
        int mid = (curr->start + curr->end) / 2;
        if (end <= mid)
            return sumTreeRange(curr->left, start, end);
        else if (start > mid)
            return sumTreeRange(curr->right, start, end);
        else
            return sumTreeRange(curr->left, start, mid) + sumTreeRange(curr->right, mid + 1, end);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);