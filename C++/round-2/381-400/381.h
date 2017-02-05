class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = index.find(val) == index.end() || index[val].empty();
        data.push_back(make_pair(val, index[val].size()));
        index[val].push_back(data.size() - 1);
        return flag;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool flag = index.find(val) != index.end() && index[val].size();
        if (flag) {
            auto last = data.back();
            index[last.first][last.second] = index[val].back();
            data[index[val].back()] = last;
            index[val].pop_back();
            data.pop_back();
        }
        return flag;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return data[rand() % data.size()].first;
    }
private:
    unordered_map<int, vector<int>> index;  // use 2D index instead of 1D
    vector<pair<int, int>> data;
};