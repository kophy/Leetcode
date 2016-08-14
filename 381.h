class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        index[val].push_back(data.size());
        data.push_back(val);
        return (index[val].size() == 1);
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (index.find(val) == index.end() || index[val].size() == 0)
            return false;
        int pivot = index[val].back();
        index[data.back()].back() = pivot;
        data[pivot] = data.back();
        index[val].pop_back();
        data.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return data[rand() % data.size()];
    }

private:
    vector<int> data;
    map<int, vector<int>> index;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */