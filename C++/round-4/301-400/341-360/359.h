class Logger {
public:
	/** Initialize your data structure here. */
	Logger() {}

	/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
	    If this method returns false, the message will not be printed.
	    The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		bool flag = false;
		if (lastTime.find(message) == lastTime.end() || timestamp - lastTime[message] >= 10) {
			flag = true;
			lastTime[message] = timestamp;
		}
		return flag;
	}

private:
	unordered_map<string, int> lastTime;
};