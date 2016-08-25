class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int sLen = s.size();
        int wSize = words.size();
        if(sLen == 0 || wSize == 0)
            return result;
        int l = words[0].length();

        map<string, int> w;
        for (int i = 0; i < wSize; ++i)
            ++w[words[i]];

        for(int i = 0; i <= sLen - wSize * l; ++i) {
            auto ww = w;
            int j = i;
            for( ; j < i + wSize * l; j += l) {
                string temp = s.substr(j, l);
                if(ww.find(temp) != ww.end() && ww[temp] > 0)
                    --ww[temp];
                else
                    break;
            }
            if(j == i + wSize * l)
                result.push_back(i);
        }
        return result;
    }
};