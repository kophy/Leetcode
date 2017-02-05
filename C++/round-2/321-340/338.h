class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        while (result.size() < num + 1) {
            int n = result.size();
            for (int i = 0; i < n && result.size() < num + 1; ++i)
                result.push_back(result[i] + 1);
        }
        return result;
    }
};