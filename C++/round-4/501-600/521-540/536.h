class Solution {
public:
    TreeNode *str2tree(string s) {
        if (s.empty())
            return nullptr;
        
        stack<TreeNode *> data;
        data.push(new TreeNode(0));
        
        int d = 0, flag = 1;
        int pos = 0;
        while (pos < s.size()) {
            char c = s[pos];
            if (c == '-' || isdigit(c)) {
                int i = 1;
                while (pos + i < s.size() && isdigit(s[pos + i]))
                    ++i;
                data.top()->val = stoi(s.substr(pos, i));
                pos += i;
            } else if (c == '(') {
                TreeNode *node = new TreeNode(0);
                if (data.top()->left)
                    data.top()->right = node;
                else
                    data.top()->left = node;
                data.push(node);
                ++pos;
            } else {
                data.pop();
                ++pos;
            }
        }
        
        return data.empty()? nullptr : data.top();
    }
};