class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0)
            return true;
        if (desiredTotal > (1 + maxChoosableInteger) * maxChoosableInteger / 2)
            return false;
        unsigned int used = 0;
        return canForceWin(desiredTotal, used, maxChoosableInteger);
    }

private:
    map<unsigned int, bool> record;     // record pattern

    bool canForceWin(int total, unsigned int &used, int maxInt) {
        if (record.find(used) != record.end())
            return record[used];
        bool canWin = false;
        for (int i = 1; i <= maxInt && !canWin; ++i) {
            unsigned int mask = (1 << i);
            if (!(used & mask)) {
                used |= mask;
                canWin = (i >= total) || !canForceWin(total - i, used, maxInt);
                used &= ~mask;
                if (canWin)
                    break;
            }
        }
        record[used] = canWin;
        return canWin;
    }
};