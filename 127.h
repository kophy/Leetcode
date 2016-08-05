class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> begin_set, end_set, visited;
        begin_set.insert(beginWord);
        end_set.insert(endWord);

        int len = 0;
        while (!begin_set.empty() && !end_set.empty()) {
            if (begin_set.size() > end_set.size())
                swap(begin_set, end_set);
            ++len;
            unordered_set<string> temp_set;
            for (auto iter = begin_set.begin(); iter != begin_set.end(); ++iter) {
                string temp = *iter;
                for (int i = 0; i < temp.size(); ++i) {
                    char origin_c = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (wordList.find(temp) == wordList.end())
                            continue;
                        if (visited.find(temp) == visited.end()) {
                            visited.insert(temp);
                            temp_set.insert(temp);
                        }
                        if (end_set.find(temp) != end_set.end())
                            return len + 1;
                    }
                    temp[i] = origin_c;
                }
            }
            begin_set = temp_set;
        }
        return 0;
    }
};