class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        if (S.size() == 0)
			return S;
		int j = 0;
		for (int i = 0; i < S.size(); ++i) {
			if (!isalnum(S[i]))
				continue;
			else if (isdigit(S[i]))
				S[j++] = S[i];
			else if (S[i] >= 'A' && S[i] <= 'Z')
				S[j++] = S[i];
			else
				S[j++] = S[i] + ('A' - 'a');
		}
		int len = j, pos = 0, cur = 0;
		string result(len + (len - 1) / K, ' ');
		if (len % K) {
			for (int i = 0; i < len % K; ++i)
				result[cur++] = S[i];
			pos += len % K;
			if (pos < len)
			    result[cur++] = '-';
		}
		while (pos < len) {
			for (int i = pos; i < pos + K; ++i)
				result[cur++] = S[i];
			pos += K;
			if (pos < len)
			    result[cur++] = '-';
		}
		return result;
    }
};