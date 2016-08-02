class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i)
            result = recur(result);
        return result;
    }
private:
    string recur(string s) {
        string result;
        char pre = s[0];
        int count = 1;
        for(int i = 1; i <= s.size(); ++i) {
            if (i == s.size() || s[i] != pre) {
                char tmp =  count + '0';
                result = result + tmp + pre;
                pre = s[i];
                count = 1;
            } else
                ++count;
        }
        return result;
    }
};