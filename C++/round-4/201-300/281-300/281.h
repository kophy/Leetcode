class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            begins.push(v1.begin());
            ends.push(v1.end());
        }
        if (!v2.empty()) {
            begins.push(v2.begin());
            ends.push(v2.end());
        }
    }

    int next() {
        auto b = begins.front(), e = ends.front();
        begins.pop();
        ends.pop();
        
        int result = *b;
        if (++b != e) {
            begins.push(b);
            ends.push(e);
        }
        return result;
    }

    bool hasNext() {
        return !begins.empty();
    }
    
private:
    queue<vector<int>::iterator> begins;
    queue<vector<int>::iterator> ends;
};
