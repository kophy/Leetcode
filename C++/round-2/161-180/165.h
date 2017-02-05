class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        int num1, num2;
        char dummy;

        /********************************************
        	need to go over C++ IO stream
        ********************************************/
        while (!ss1.fail() || !ss2.fail()) {
            ss1 >> num1;

            // the stream fails when a read operation fails, so don't put dummy before this judge!
            if (ss1.fail())
                num1 = 0;
            ss1 >> dummy;	// handle character '.'

            ss2 >> num2;
            if (ss2.fail())
                num2 = 0;
            ss2 >> dummy;
            if (num1 > num2)
                return 1;
            if (num1 < num2)
                return -1;
        }
        return 0;
    }
};