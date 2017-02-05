class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0)
            return false;
        unordered_set<int> visited;
        visited.insert(n);
        while (n != 1) {
            n = happy(n);
            if (visited.count(n))
                return false;
            visited.insert(n);
        }
        return true;
    }
    
private:
    int happy(int n) {
        int result = 0;
        while (n) {
            result += pow(n % 10, 2);
            n /= 10;
        }
        return result;
    }
};