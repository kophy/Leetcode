class Solution {
public:
    int romanToInt(string s) {
        int dic[26];
        dic['I'-'A'] = 1;
        dic['V'-'A'] = 5;
        dic['X'-'A'] = 10;
        dic['L'-'A'] = 50;
        dic['C'-'A'] = 100;
        dic['D'-'A'] = 500;
        dic['M'-'A'] = 1000;

        int result = dic[s[0]-'A'];
        char pre = s[0];
        for(int i = 1; i < s.size(); ++i) {
            result += dic[s[i] - 'A'];
            if(dic[s[i] - 'A'] > dic[pre - 'A'])
                result -= 2 * dic[pre - 'A'];
            pre = s[i];
        }
        return result;
    }
};