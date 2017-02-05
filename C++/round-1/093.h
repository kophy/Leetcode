class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<int> ip(4, 0);
        restore_helper(result, s, 0, ip, 0);
        return result;
    }
private:
    string itoa(int d) {
        stringstream ss;
        ss << d;
        return ss.str();
    }
    void restore_helper(vector<string> &result, string s, int s_pos, vector<int> ip, int ip_pos) {
        if (s_pos == s.size() && ip_pos == 4) {
            string curr_ip = itoa(ip[0]);
            for (int i = 1; i < 4; ++i)
                curr_ip += "." + itoa(ip[i]);
            result.push_back(curr_ip);
        }
        if ((s_pos == s.size() && ip_pos < 4) || (s_pos < s.size() && ip_pos == 4))
            return;
        ip[ip_pos] = 0;
        while (s_pos < s.size()) {
            ip[ip_pos] = ip[ip_pos] * 10 + (s[s_pos++] - '0');
            if (ip[ip_pos] == 0) {
                restore_helper(result, s, s_pos, ip, ip_pos + 1);
                break;
            } else if (ip[ip_pos] > 255)
                break;
            else
                restore_helper(result, s, s_pos, ip, ip_pos + 1);
        }
    }
};