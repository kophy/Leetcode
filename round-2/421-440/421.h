class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        int result = 0;
for (auto num : nums) {
            int value = search(num);
            insert(num);
            result = max(result, value);
        }
        return result;
    }

private:
    typedef struct TrieNode {
        TrieNode *c[2];
        TrieNode() {
            c[0] = NULL;
            c[1] = NULL;
        }
    };

    TrieNode *root;

    void insert(int num) {
        TrieNode *p = root;
        for (int i = 31; i >= 0; --i) {
            int d = (num >> i) & 1;
            if (!p->c[d])
                p->c[d] = new TrieNode();
            p = p->c[d];
        }
    }

    int search(int num) {
        int value = 0;
        TrieNode *p = root;
        for (int i = 31; i >= 0; i--) {
            int d = (num >> i) & 1;
            // find "complementary"
            if (p->c[1 - d]) {
                p = p->c[1 - d];
                value |= (1 << i);
            } else if(p->c[d])
                p = p->c[d];
        }
        return value;
    }
};