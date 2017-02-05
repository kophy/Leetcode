class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> lengths = {0};
        istringstream is(input);
        string temp;
        int max_len = 0;
        while (getline(is, temp, '\n')) {
            int cnt = 0;
            // number of '\t' suggests level of current item
            while (temp[cnt] == '\t')
                ++cnt;
            string item = temp.substr(cnt);
            // case 1: file
            if (item.find('.') != string::npos)
                max_len = max(max_len, lengths[cnt] + (int)item.size());
            // case 2: directory
            else {
                if (lengths.size() <= cnt + 1)
                    lengths.push_back(-1);
                lengths[cnt + 1] = lengths[cnt] + item.size() + 1;  // 1 is for '/'
            }
        }
        return max_len;
    }
};