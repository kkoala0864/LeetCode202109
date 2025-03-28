#include <string>
#include <unordered_map>
#include <map>

using std::map;
using std::unordered_map;

using std::string;

class TimeMap {
public:
	TimeMap() {
	}

	void set(string key, string value, int timestamp) {
		_m[key][timestamp] = value;
	}

	string get(string key, int timestamp) {
		if (_m.find(key) == _m.end())
			return "";
		auto iter = _m[key].lower_bound(timestamp);

		if (iter->first == timestamp)
			return iter->second;
		else {
			if (iter == _m[key].begin())
				return "";
			else {
				--iter;
				return iter->second;
			}
		}
	}

private:
	unordered_map<string, map<int, string>> _m;
	virtual ~TimeMap() {
	}
	TimeMap &operator=(const TimeMap &source);
	TimeMap(const TimeMap &);
};
