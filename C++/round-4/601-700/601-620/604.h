class StringIterator {
public:
	StringIterator(string compressedString) {
		int pos = 0;
		while (pos < compressedString.size()) {
			char c = compressedString[pos++];
			int d = 0;
			while (pos < compressedString.size() && isdigit(compressedString[pos])) {
				d = d * 10 + compressedString[pos] - '0';
				++pos;
			}
			data.push_back(make_pair(c, d));
		}
	}

	char next() {
		if (!hasNext())
			return ' ';
		char c = data.begin()->first;
		if (--data.begin()->second == 0)
			data.pop_front();
		return c;
	}

	bool hasNext() {
		return !data.empty();
	}

private:
	list<pair<char, int>> data;
};