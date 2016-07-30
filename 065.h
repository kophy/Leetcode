class Solution {
public:
    bool isNumber(string s) {
        int start = 0, end = s.size() - 1;
        while (start < s.size() && s[start] == ' ') {
            start++;
        }
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        int state = 0;
        for (int i =  start; i <= end; i++) {
            char c = s[i];
            switch (state) {
            case 0:
                if (c == '+' || c == '-') {
                    state = 1;
                } else if (c >= '0' && c <= '9') {
                    state = 2;
                } else if (c == '.') {
                    state = 6;
                } else {
                    return false;
                }
                break;
            case 1:
                if (c >= '0' && c <= '9') {
                    state = 2;
                } else if (c == '.') {
                    state = 6;
                } else {
                    return false;
                }
                break;
            case 2:
                if (c >= '0' && c <= '9') {
                    state = 2;
                } else if (c == '.') {
                    state = 3;
                } else if (c == 'e') {
                    state = 5;
                } else {
                    return false;
                }
                break;
            case 3:
                if (c >= '0' && c <= '9') {
                    state = 4;
                } else if (c == 'e') {
                    state = 5;
                } else {
                    return false;
                }
                break;
            case 4:
                if (c >= '0' && c <= '9') {
                    state = 4;
                } else if (c == 'e') {
                    state = 5;
                } else {
                    return false;
                }
                break;
            case 5:
                if (c >= '0' && c <= '9') {
                    state = 7;
                } else if (c == '+' || c == '-') {
                    state = 8;
                } else {
                    return false;
                }
                break;
            case 6:
                if (c >= '0' && c <= '9') {
                    state = 4;
                } else {
                    return false;
                }
                break;
            case 7:
                if (c >= '0' && c <= '9') {
                    state = 7;
                } else {
                    return false;
                }
                break;
            case 8:
                if (c >= '0' && c <= '9') {
                    state = 7;
                } else {
                    return false;
                }
                break;
            }
        }
        return state == 2 || state == 3 || state == 4 || state == 7;
    }
};