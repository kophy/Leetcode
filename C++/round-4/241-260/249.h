class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> data;
        for (string &str : strings) {
            string key = makeKey(str);
            data[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto &p : data)
            result.push_back(p.second);
        return result;
    }
    
private:
    string makeKey(string &str) {
        string key = "0";
        for (int i = 1; i < str.size(); ++i)
            key += "@" + to_string((str[i] - str[0] + 26) % 26);
        return key;
    }
};