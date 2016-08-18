class Solution {
public:
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        string result = convert3(num % 1000);
        num /= 1000;
        if (num % 1000)
            result = convert3(num % 1000) + " Thousand" + (result.size()? " " + result : "");
        num /= 1000;
        if (num % 1000)
            result = convert3(num % 1000) + " Million" + (result.size()? " " + result : "");
        num /= 1000;
        if (num % 1000)
            result = convert3(num % 1000) + " Billion" + (result.size()? " " + result : "");
        return result;
    }
private:
    string convert_ones[10] = {"Zero", "One", "Two", "Three", "Four", "Five",
                               "Six", "Seven", "Eight", "Nine"
                              };
    string convert_tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                               "Sixty", "Seventy", "Eighty", "Ninety"
                              };
    string convert_onex[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                               "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
                              };

    string convert3(int n) {
        string s = "";
        int h = n / 100;
        if (h >= 1)
            s += convert_ones[h] + " Hundred";
        n %= 100;
        int t = n / 10;
        if (t >= 2) {
            if (s.size())
                s += " ";
            s += convert_tens[t];
        } else if (t == 1) {
            if (s.size())
                s += " ";
            s += convert_onex[n - 10];
            return s;
        }
        n %= 10;
        if (n >= 1) {
            if (s.size())
                s += " ";
            s += convert_ones[n];
        }
        return s;
    }
};