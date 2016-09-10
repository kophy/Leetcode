class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<int> path;

        /*  avoid large scale problem which can be easily handled */
        if (s.size() <= 12)
            restore(result, s, path, 0);
        return result;
    }

private:
    void restore(vector<string> &result, string &s, vector<int> path, int pos) {
        if (pos == s.size() && path.size() == 4) {
            string ip = to_string(path[0]);
            for (int i = 1; i < 4; ++i)
                ip += "." + to_string(path[i]);
            result.push_back(ip);
            return;
        }
        /*  case '0' must be handled separately
        	it can not be the begin of a number(except 0 itself)
        */
        if (s[pos] == '0') {
            path.push_back(0);
            restore(result, s, path, pos + 1);
            return;
        } else {
            int temp = 0;
            for (int i = 0; i < 3 && pos + i < s.size(); ++i) {
                temp = temp * 10 + (s[pos + i] - '0');
                if (temp >= 0 && temp <= 255) {
                    path.push_back(temp);
                    restore(result, s, path, pos + i + 1);
                    path.pop_back();
                }
            }
        }
    }
};