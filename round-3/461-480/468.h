class Solution {
public:
    string validIPAddress(string IP) {
        stringstream ss(IP);
        string block;
        // ipv4 candidate
        if (IP.substr(0, 4).find('.') != string::npos) {
            for (int i = 0; i < 4; ++i)
                if (!getline(ss, block, '.') || !isValidIPv4Block(block))
                    return "Neither";
            return ss.eof()? "IPv4" : "Neither";
        }
        // ipv6 candidate
        else if (IP.substr(0, 5).find(':') != string::npos) {
            for (int i = 0; i < 8; ++i)
                if (!getline(ss, block, ':') || !isValidIPv6Block(block))
                    return "Neither";
            return ss.eof() ? "IPv6" : "Neither";
        } else
            return "Neither";
    }

private:

    const string validIPv6Chars = "0123456789abcdefABCDEF";

    bool isValidIPv4Block(string &block) {
        if (block.size() <= 0 || block.size() > 3)
            return false;
        int num = 0;
        for (int i = 0; i < block.size(); ++i) {
            char c = block[i];
            if (!isdigit(c) || (i == 0 && c == '0' && block.size() > 1))
                return false;
            num = num * 10 + (c - '0');
        }
        return num <= 255;
    }

    bool isValidIPv6Block(string &block) {
        if (block.size() <= 0 || block.size() > 4)
            return false;
        for (int i = 0; i < block.size(); i++) {
            char c = block[i];
            if (validIPv6Chars.find(c) == string::npos)
                return false;
        }
        return true;
    }
};