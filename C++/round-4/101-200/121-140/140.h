class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> cache;
        return helper(cache, s, wordSet);
    }
    
private:
    vector<string> helper(unordered_map<string, vector<string>> &cache, string s, unordered_set<string> &wordSet) {
        if (cache.count(s))
            return cache[s];
        
        vector<string> result;
        if (wordSet.count(s))
            result.push_back(s);
        
        for (int i = 0; i < s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (wordSet.count(prefix)) {
                string rest = s.substr(i);
                vector<string> suffixes = helper(cache, rest, wordSet);
                for (string &suffix : suffixes)
                    result.push_back(prefix + " " + suffix);
            }
        }
        cache[s] = result;
        return result;
    }
};