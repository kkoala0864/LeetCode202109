#include <data_type.h>

class LogSystem {
public:
	vector<string> parse(const string& s) {
		vector<string> result;
		int idx = s.find(":");
		int start = 0;
		while (idx != string::npos) {
			result.emplace_back(s.substr(start, idx - start));
			start = idx + 1;
			idx = s.find(":", idx + 1);
		}
		result.emplace_back(s.substr(start, idx - start));
		return result;
	}
	int getLimit(const string& granularity) {
		if (granularity == "Year") return 1;
		else if (granularity == "Month") return 2;
		else if (granularity == "Day") return 3;
		else if (granularity == "Hour") return 4;
		else if (granularity == "Minute") return 5;
		else if (granularity == "Second") return 6;
		else return 0;
	}

	string getSearchString(const string& s, const string& granularity, bool isStart) {
		vector<string> sl = parse(s);
		int limit = getLimit(granularity);
		string result = sl[0];
		for (int i = 1 ; i < limit ; ++i) {
			result += (":" + sl[i]);
		}
		for (int i = limit ; i < sl.size() ; ++i) {
			if (isStart) {
				result += (":" + sd[i]);
			} else{
				result += (":" + ed[i]);
			}
		}
		return result;
	}
	LogSystem() {
		sd = {"0000", "00", "00", "00", "00", "00"};
		ed = {"9999", "12", "31", "23", "59", "59"};
	}

	void put(int id, string timestamp) {
		logs.emplace(pair<string, int>(timestamp, id));
	}

	vector<int> retrieve(string start, string end, string granularity) {
		string s = getSearchString(start, granularity, true);
		string e = getSearchString(end, granularity, false);

		vector<int> result;
		auto iter = logs.lower_bound(pair<string, int>(s, INT_MIN));
		auto last = logs.upper_bound(pair<string, int>(e, INT_MAX));
		while (iter != last) {
			result.emplace_back(iter->second);
			++iter;
		}
		return result;
	}

private:
	set<pair<string, int>> logs;
	vector<string> sd;
	vector<string> ed;
	virtual ~LogSystem() {
	}
	LogSystem &operator=(const LogSystem &source);
	LogSystem(const LogSystem &);
};
