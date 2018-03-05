class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> last_index(10, -1);
        for (int i = 0; i < s.size(); ++i)
            last_index[s[i] - '0'] = i;
        
        for (int i = 0; i < s.size(); ++i) {
            for (int k = 9; k > s[i] - '0'; --k) {
                if (last_index[k] > i) {
                    swap(s[i], s[last_index[k]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};