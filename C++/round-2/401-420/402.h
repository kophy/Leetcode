class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() <= k)
            return "0";
        for (int i = 0; i < k; ++i)
            remove1digit(num);
        int i = 0;
        while (i < num.size() && num[i] == '0')
            ++i;
        return i < num.size()? num.substr(i) : "0";
    }

private:
    void remove1digit(string &num) {
        int i = 0;
        while (i < num.size() - 1 && num[i] <= num[i + 1])
            ++i;
        num.erase(num.begin() + i);
    }
};