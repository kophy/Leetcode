class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        int num1 = 0, num2 = 0;
        char dummy;
        
        while(!ss1.fail() || !ss2.fail()){
            ss1 >> num1;
            if(ss1.fail())
                num1 = 0;
			ss2 >> num2;
            if(ss2.fail())
                num2 = 0;
            if (num1 != num2)
				return (num1 > num2)? 1 : -1;
            ss1 >> dummy;
            ss2 >> dummy;
        }
        return 0;
    }
};