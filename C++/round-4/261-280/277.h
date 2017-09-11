// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	// two pass: find and check
	int findCelebrity(int n) {
		if (n == 0)
			return -1;
		int celebrity = 0;
		for (int i = 1; i < n; ++i)
			celebrity = knows(celebrity, i)? i : celebrity;
		for (int i = 0; i < n; ++i)
			if (celebrity != i && (knows(celebrity, i) || !knows(i, celebrity)))
				return -1;
		return celebrity;
	}
};