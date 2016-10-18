class LRUCache {
public:
    LRUCache(int capacity) {
        limit = capacity;
    }

    int get(int key) {
        auto iter = occurance.find(key);
        /* case 1: record not exists, nothing happens */
        if (iter == occurance.end())
            return -1;
        /* case 2: record exists, move it to front */
        data.push_front(*(iter->second));
        data.erase(iter->second);
        iter->second = data.begin();
        return iter->second->second;
    }

    void set(int key, int value) {
        auto iter = occurance.find(key);
        /* case 1: insert new pair */
        if (iter == occurance.end()) {
            while (occurance.size() >= limit) {
                occurance.erase(data.back().first);
                data.pop_back();
            }
        }
        /* case 2: modify old pair */
        else
            data.erase(iter->second);
        data.push_front(make_pair(key, value));
        occurance[key] = data.begin();
    }

private:
    int limit;
    list<pair<int, int>> data;

    // list iterator doesn't change with size grow, while vector iterator does
    map<int, list<pair<int, int>>::iterator> occurance;
};