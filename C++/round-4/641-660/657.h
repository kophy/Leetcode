class Solution {
public:
	bool judgeCircle(string moves) {
		int x = 0, y = 0;
		for (char m : moves) {
			switch (m) {
			case 'U' :
				++y;
				break;
			case 'D' :
				--y;
				break;
			case 'R' :
				++x;
				break;
			case 'L' :
				--x;
				break;
			}
		}
		return x == 0 && y == 0;
	}
};