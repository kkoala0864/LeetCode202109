#include <data_type.h>

class Router {
public:
	static string getHash(int source, int destination, int timestamp) {
		return to_string(source) + "|" + to_string(destination) + "|" + to_string(timestamp);
	}

	Router(int memoryLimit) {
		size = memoryLimit;
	}

	bool addPacket(int source, int destination, int timestamp) {
		string key = getHash(source, destination, timestamp);
		if (us.count(key)) return false;
		us.emplace(key);

		if (info.size() == size) {
			forwardPacket();
		}
		info.push_back({source, destination, timestamp});
		dt[destination].emplace_back(timestamp);
		return true;
	}

	vector<int> forwardPacket() {
		if (info.empty()) return {};
		int ls = info.front()[0];
		int ld = info.front()[1];
		int lt = info.front()[2];
		info.pop_front();
		us.erase(getHash(ls, ld, lt));
		dt[ld].pop_front();
		return {ls, ld, lt};
	}

	int getCount(int destination, int startTime, int endTime) {
		int l = lower_bound(dt[destination].begin(), dt[destination].end(), startTime) - dt[destination].begin();
		int r = upper_bound(dt[destination].begin(), dt[destination].end(), endTime) - dt[destination].begin();
		return r - l;
	}

private:
	deque<vector<int>> info;
	unordered_map<int, deque<int>> dt;
	unordered_set<string> us;
	int size;
	virtual ~Router() {
	}
	Router &operator=(const Router &source);
	Router(const Router &);
};
