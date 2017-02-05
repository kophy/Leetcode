class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> data;
        for (int i = 0; i < strs.size(); ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            data[temp].push_back(strs[i]);
        }
        for (auto iter = data.begin(); iter != data.end(); ++iter)
            result.push_back(iter->second);
        return result;
    }
};