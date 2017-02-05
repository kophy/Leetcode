class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty())
            return true;
        istringstream ss(preorder);
        int capacity = 1;
        int pos = 0;
        while (pos < preorder.size()) {
            if (isdigit(preorder[pos])) {
                if (--capacity < 0)
                    return false;
                capacity += 2;
                while (pos < preorder.size() && isdigit(preorder[pos]))
                    ++pos;
            } else if (preorder[pos] == '#') {
                --capacity;
                ++pos;
            } else
                ++pos;
        }
        return capacity == 0;
    }
};