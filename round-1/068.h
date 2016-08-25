class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int cnt, len;
        for(int i = 0; i < words.size(); i += cnt) {
            cnt = len = 0;
            for(; i + cnt < words.size() && len + words[i + cnt].size() <= maxWidth - cnt; ++cnt)
                len += words[i + cnt].size();

            string temp = words[i];
            for(int j = 0; j < cnt - 1; ++j) {
                if(i + cnt == words.size())
                    temp += " ";
                else
                    temp += string((maxWidth - len) / (cnt - 1) + (j < (maxWidth - len) % (cnt - 1)), ' ');
                temp += words[i + j + 1];
            }
            temp += string(maxWidth - temp.size(), ' ');
            result.push_back(temp);
        }
        return result;
    }
};