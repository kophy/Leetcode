class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        auto iter = occurance.find(key);
        if (iter == occurance.end())
            return -1;
        data.push_front(*iter->second);
        data.erase(iter->second);
        iter->second = data.begin();
        return iter->second->second;
    }

    void set(int key, int value) {
        auto iter = occurance.find(key);
        if (iter == occurance.end()) {
            while (occurance.size() >= _capacity) {
                occurance.erase(data.back().first);
                data.pop_back();
            }
        } else {
            data.erase(iter->second);
        }
        data.push_front(pair<int, int>(key, value));
        occurance[key] = data.begin();
    }
private:
    int _capacity;
    list<pair<int, int>> data;
    map<int, list<pair<int, int>>::iterator> occurance;
};