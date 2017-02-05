class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        int i = 0;
        while (i < words.size()) {
            int count = 0, length = 0;

            /* calculate how many words should be included in this line */
            while (i + count < words.size() && length + words[i + count].size() + count <= maxWidth) {
                length += words[i + count].size();
                ++count;
            }

            /* construct this line from words and spaces */
            string temp = words[i];
            for (int j = 1; j < count; ++j) {
                // last line is left justified
                if (i + count == words.size())
                    temp += " ";
                else {
                    int space_count = maxWidth - length;
                    int slot_count  = count - 1;

                    // Divide spaces as even as possible. If can not, assign more spaces to left slots than right.
                    temp += string(space_count / slot_count + (j <= space_count % slot_count), ' ');
                }
                temp += words[i + j];
            }
            temp += string(maxWidth - temp.size(), ' ');
            result.push_back(temp);
            i += count;
        }

        return result;
    }
};