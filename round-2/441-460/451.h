class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            ++count[c];
        vector<pair<char, int>> data;
        for (auto p : count)
            data.push_back(p);
        sort(data.begin(), data.end(), [](pair<char, int> &a, pair<char, int> &b)->bool{
            return a.second > b.second;
        });
        string result = "";
        for (auto p : data)
            result += string(p.second, p.first);
        return result;
    }
};