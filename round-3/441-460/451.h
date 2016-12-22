class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c: s)
            ++count[c];
        vector<pair<char, int>> data;
        for (auto iter = count.begin(); iter != count.end(); ++iter)
            data.push_back(make_pair(iter->first, iter->second));
        sort(data.begin(), data.end(), [](pair<char, int> &a, pair<char, int> &b) -> bool {
            return a.second > b.second;
        });
        string result = "";
        for (auto iter = data.begin(); iter != data.end(); ++iter)
            result += string(iter->second, iter->first);
        return result;
    }
};