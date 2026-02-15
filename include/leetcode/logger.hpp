#include <cassert>
#include <map>
#include <string>
#include <utility>

class Logger {
public:
	/** Initialize your data structure here. */
	Logger() {
	}

	/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
	    If this method returns false, the message will not be printed.
	    The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, std::string message) {
		auto iter = messages.find(message);
		if (iter != messages.end()) { // message is already stored
			auto diff = timestamp - iter->second;
			if (diff >= 10) {
				iter->second = timestamp;
				return true;
			}
			return false;
		}
		messages.insert(std::pair<std::string, int>(message, timestamp));
		return true;
	}

private:
	std::map<std::string, int> messages;
};

void run_logger() {
	Logger logger;

	// logging string "foo" at timestamp 1
	assert(logger.shouldPrintMessage(1, "foo") == true);

	// logging string "bar" at timestamp 2
	assert(logger.shouldPrintMessage(2, "bar") == true);

	// logging string "foo" at timestamp 3
	assert(logger.shouldPrintMessage(3, "foo") == false);

	// logging string "bar" at timestamp 8
	assert(logger.shouldPrintMessage(8, "bar") == false);

	// logging string "foo" at timestamp 10
	assert(logger.shouldPrintMessage(10, "foo") == false);

	// logging string "foo" at timestamp 11
	assert(logger.shouldPrintMessage(11, "foo") == true);
}
/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */