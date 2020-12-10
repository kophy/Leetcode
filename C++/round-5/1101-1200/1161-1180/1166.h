typedef struct Node {
    bool is_file;
    int value;
    unordered_map<string, Node *> children;
    
    Node(): is_file(false), value(0) {}
};

class FileSystem {
public:
    FileSystem() {
        root = new Node();
    }
    
    bool createPath(const string &path, int value) {
        if (get(path) != -1) {
            return false;
        }
        
        vector<string> partitions = splitPath(path);
        if (partitions.empty()) {
            return false;
        }
        Node *node = root;
        for (int i = 0; i < (int)partitions.size() - 1; ++i) {
            const string &p = partitions[i];
            if (!node->children.count(p)) {
                return false;
            }
            node = node->children[p];
        }
        
        const string &p = partitions.back();
        node->children[p] = new Node();
        node = node->children[p];
        
        node->is_file = true;
        node->value = value;
        return true;
    }
    
    int get(const string &path) {
        vector<string> partitions = splitPath(path);
        if (partitions.empty()) {
            return -1;
        }
        Node *node = root;
        for (const string &p : partitions) {
            if (!node->children.count(p)) {
                return -1;
            }
            node = node->children[p];
        }
        if (!node->is_file) {
            return -1;
        }
        return node->value;
    }
    
private:
    Node *root;
    
    vector<string> splitPath(string path) {        
        if (path.empty() || path[0] != '/') {
            return {};
        }
        vector<string> result;
        int begin = 1;
        for (int i = 1; i <= path.size(); ++i) {
            if (i == path.size() || path[i] == '/') {
                string p = path.substr(begin, i - begin);
                result.push_back(p);
                begin = i + 1;
            }
        }
        return result;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */