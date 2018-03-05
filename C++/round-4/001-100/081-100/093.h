class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.size() >= 4 && s.size() <= 12) {
            vector<int> candidate;
            backtracking(result, s, 0, candidate);
        }
        return result;
    }
    
private:
    void backtracking(vector<string> &result, string &s, int pos, vector<int> &candidate) {
        if (pos == s.size()) {
            if (candidate.size() == 4) {
                string ip = to_string(candidate[0]);
                for (int i = 1; i < 4; ++i)
                    ip += "." + to_string(candidate[i]);
                result.push_back(ip);
            }
            return;
        }
        if (candidate.size() == 4)
            return;
        
        if (s[pos] == '0') {
            candidate.push_back(0);
            backtracking(result, s, pos + 1, candidate);
            candidate.pop_back();
        } else {
            int temp = 0;
            for (int i = 0; i < 3 && pos + i < s.size(); ++i) {
                temp = temp * 10 + (s[pos + i] - '0');
                if (temp >= 0 && temp <= 255) {
                    candidate.push_back(temp);
                    backtracking(result, s, pos + i + 1, candidate);
                    candidate.pop_back();
                }
            }
        }
    }
};