class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> data;
        for (char c : s) {
            if (data.empty() || data.back().first != c) {
                data.push_back(std::make_pair(c, 1));
            } else {
                data.back().second++;
                if (data.back().second == k) {
                    data.pop_back();
                }
            }
        }
        
        string result;
        for (const auto &p : data) {
            result += string(p.second, p.first);
        }
        return result;
    }
};