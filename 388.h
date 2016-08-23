class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> lengths = {0};
        istringstream is(input);
        string line;
        int result = 0, t;
        while (getline(is, line, '\n')) {
            int cnt = 0;
            while (line[cnt] == '\t')
                ++cnt;
            line = line.substr(cnt);
            if (line.find('.') != string::npos) {
                t = lengths[cnt] + line.length();
                result = max(result, t);
            } else {
                t = lengths[cnt] + line.length() + 1;
                if (lengths.size() <= cnt + 1)
                    lengths.push_back(t);
                else
                    lengths[cnt + 1] = t;
            }
        }
        return result;
    }
};