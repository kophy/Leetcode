class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty())
            return false;
        preorder += ",";
        int capacity = 1, i = 0;
        while (i < preorder.size()) {
            if (--capacity < 0)
                return false;
            if (preorder[i] != '#')
                capacity += 2;
            
            while (preorder[i] != ',')
                ++i;
            ++i;    // skip ','
        }
        return capacity == 0;
    }
};