class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int i = 0, j = (int)num.size() - 1;
        while (i <= j) {
            if (!m.count(num[i]) || m[num[i]] != num[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};