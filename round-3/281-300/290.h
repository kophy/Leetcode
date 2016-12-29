class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> data = splitString(str);
        if (pattern.size() != data.size())
            return false;
        unordered_map<char, string> mapping;
        unordered_set<string> visited;
        for (int i = 0; i < pattern.size(); ++i) {
            if (mapping.find(pattern[i]) != mapping.end()) {
                if (mapping[pattern[i]] != data[i])
                    return false;
            } else {
                if (visited.find(data[i]) != visited.end())
                    return false;
                mapping[pattern[i]] = data[i];
                visited.insert(data[i]);
            }
        }
        return true;
    }

private:
    vector<string> splitString(string str) {
        stringstream ss(str);
        string temp;
        vector<string> data;
        while (ss >> temp)
            data.push_back(temp);
        return data;
    }
};