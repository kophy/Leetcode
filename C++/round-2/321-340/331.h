class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty())
            return true;
        preorder += ",";
        int capacity = 1;

        char last = '@';
        for (char c : preorder) {
            if (c == ',') {
                if (--capacity < 0)
                    return false;
                if (isdigit(last))
                    capacity += 2;
            }
            last = c;
        }
        return capacity == 0;
    }
};