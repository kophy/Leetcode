class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> data;
        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            data[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto iter = data.begin(); iter != data.end(); ++iter)
            result.push_back(iter->second);
        return result;
    }
};