// version 1
class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        string temp;
        vector<string> words;
        while (ss >> temp)
            words.push_back(temp);
        string reversed;
        for (int i = words.size() - 1; i >= 0; --i)
            reversed += words[i] + (i == 0? "" : " ");
        s = reversed;
    }
};

// version 2
class Solution {
public:
    void reverseWords(string &s) {        
        // 1. remove extra space
        int j = 0, count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isspace(s[i]))
                ++count;
            else
                count = 0;
            if (count <= 1)
                s[j++] = s[i];
        }
        fill(s.begin() + j, s.end(), ' ');
        
        // 2. reverse sentence, then reverse each word
        reverse(s.begin(), s.end());
        int begin = 0, end = 0;
        while (end < s.size()) {
            while (end < s.size() && !isspace(s[end]))
                ++end;
            reverse(s.begin() + begin, s.begin() + end);
            begin = end + 1;
            end = begin;
        }
        
        // 3. strip leading and trailing spaces
        int lead = 0, trail = s.size() - 1;
        while (lead < s.size() && isspace(s[lead]))
            ++lead;
        while (trail >= 0 && isspace(s[trail]))
            --trail;
        s = s.substr(lead, trail - lead + 1);
    }
};