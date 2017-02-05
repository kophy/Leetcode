class Solution {
public:
    /*  DYNAMIC PROGRAMMING
    	results of sub-problem can be stored in different ways -- all kinds of key-value format,
    	fine as long as they can be retrieved correctly.
    */
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (broken.find(s) != broken.end())
            return broken[s];
        vector<string> result;

        /* handle the most basic case: s itself is a word */
        if (wordDict.find(s) != wordDict.end())
            result.push_back(s);

        for (int i = 1; i < s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (wordDict.find(prefix) != wordDict.end()) {
                /* solve and store sub-problem */
                vector<string> suffixs = wordBreak(s.substr(i), wordDict);
                vector<string> temp = append(prefix, suffixs);
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }

        /* store the result */
        broken[s] = result;
        return result;
    }

private:
    /* store results for intermediate problems */
    map<string, vector<string>> broken;

    vector<string> append(string prefix, vector<string> &suffixs) {
        vector<string> result(suffixs.size());
        for (int i = 0; i < suffixs.size(); ++i)
            result[i] = prefix + " " + suffixs[i];
        return result;
    }
};