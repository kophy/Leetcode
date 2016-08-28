class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.size() == 0 || words.size() == 0)
            return result;

        int word_num = words.size(), word_len = words[0].size();
        int N = word_num * word_len;

        map<string, int> wc_save;
        for (int i = 0; i < words.size(); ++i)
            ++wc_save[words[i]];

        /* classical DFS */
        for (int i = 0; i <= (int)s.size() - N; ++i) {	// important: s.size() is unsigned!
            auto wc = wc_save;
            int j;
            for (j = i; j < i + N; j += word_len) {
                string temp = s.substr(j, word_len);
                if (wc.find(temp) != wc.end() && wc[temp] > 0)
                    --wc[temp];
                else
                    break;
            }
            if (j == i + N)
                result.push_back(i);
        }
        return result;
    }
};