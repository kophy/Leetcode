class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int data[n];
		data[0] = 1;
		int counter[primes.size()] = {0};
		
		for (int i = 1; i < n; ++i) {
		    data[i] = INT_MAX;
			for (int j = 0; j < primes.size(); ++j)
				data[i] = min(data[i], data[counter[j]] * primes[j]);
			for (int j = 0; j < primes.size(); ++j)
				if (data[i] == data[counter[j]] * primes[j])
					++counter[j];
		}
		
		return data[n - 1];
    }
};