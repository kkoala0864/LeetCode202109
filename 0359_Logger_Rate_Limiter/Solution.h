#include <data_type.h>

using namespace std;

class Logger {
public:
	Logger() {

	}

	bool shouldPrintMessage(int timestamp, string message) {
		if (messageToTime[message] > timestamp) return false;
		messageToTime[message] = max(messageToTime[message], timestamp + 10);
		return true;
	}

private:
	unordered_map<string, int> messageToTime;
	virtual ~Logger() {
	}
	Logger &operator=(const Logger &source);
	Logger(const Logger &);
};
