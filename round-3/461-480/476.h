class Solution {
public:
    int findComplement(int num) {
        bitset<32> data(num);
        int i = 31;
        while (i >= 0 && !data[i])
            --i;
        while (i >= 0)
            data.flip(i--);
        return (int)(data.to_ulong());
    }
};