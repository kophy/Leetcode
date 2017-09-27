class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {}
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++data[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto &p : data) {
            if (p.first * 2 == value) {
                if (data[p.first] > 1)
                    return true;
            } else {
                if (data.count(value - p.first))
                    return true;
            }
        }
        return false;
    }
    
private:
    unordered_map<int, int> data;
};