class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        long num = llabs(numerator), deno = llabs(denominator);
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            result += '-';
        result += to_string(num / deno);
        num %= deno;
        if(!num)
            return result;
        map<int,int> m;
        result += '.';
        while(!m.count(num)) {
            m[num] = result.size();
            num *= 10;
            while(num < deno) {
                result += '0';
                m[num] = result.size();
                num *= 10;
            }
            result += '0' + num / deno;
            num %= deno;
            if(num == 0)
                return result;
        }
        result.insert(m[num], 1, '(');
        result.insert(result.size(), 1, ')');
        return result;
    }
};