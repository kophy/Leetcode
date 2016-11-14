class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if(num.size() == 0)
            return result;
        addOperators_help(result, num, target, "", 0, 0, 0);
        return result;
    }

private:
    void addOperators_help(vector<string>& result, string &num, int &target, string path, int pos, long val, long prev) {
        // all string used, check whether value equals target
        if(pos == num.size() && val == target)
            result.push_back(path);
        for(int i = pos; i < num.size(); ++i) {
            // check illegal number
            if (num[pos] == '0' && i > pos)
                return;
            string sub_str = num.substr(pos, i - pos + 1);
            long sub_int = stol(sub_str);

            // can't add op to the first term
            if(pos == 0)
                addOperators_help(result, num, target, sub_str, i + 1, sub_int, sub_int);
            else {
                addOperators_help(result, num, target, path + "+" + sub_str, i + 1, val + sub_int, sub_int);
                addOperators_help(result, num, target, path + "-" + sub_str, i + 1, val - sub_int, -sub_int);
                /// prev is for multiplication: ...+ a * b == ...+ a + a * (b - 1)
                addOperators_help(result, num, target, path + "*" + sub_str, i + 1, val + prev * (sub_int - 1), prev * sub_int);
            }
        }
    }
};