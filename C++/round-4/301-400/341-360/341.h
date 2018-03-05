class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            auto n = nestedList[i];
            if (n.isInteger() || n.getList().size() > 0)
                data.push(n);
        }
        setUpTop();
    }

    int next() {
        auto n = data.top();
        data.pop();
        setUpTop();
        return n.getInteger();
    }

    bool hasNext() {
        return !data.empty();
    }
    
private:
    stack<NestedInteger> data;
    
    void setUpTop() {
        while (!data.empty() && !data.top().isInteger()) {
            auto list = data.top().getList();
            data.pop();
            for (int i = list.size() - 1; i >= 0; --i) {
                auto n = list[i];
                if (n.isInteger() || n.getList().size() > 0)
                    data.push(n);
            }
        }
    }
};