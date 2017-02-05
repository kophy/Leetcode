class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (index.find(val) == index.end() || index[val] == -1) {
            index[val] = data.size();
            data.push_back(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (index.find(val) == index.end() || index[val] == -1)
            return false;
        int pivot = index[val];
        index[data.back()] = pivot;
        index[val] = -1;
        swap(data[pivot], data.back());
        data.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
    }

private:
    vector<int> data;
    map<int, int> index;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */