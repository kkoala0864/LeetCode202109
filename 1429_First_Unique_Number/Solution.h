#include <data_type.h>

class FirstUnique {
public:
	void _add(int v) {
		if (valToCnt.count(v)) {
			++valToCnt[v].second;
			if (valToCnt[v].second == 2) {
				idToVal.erase(valToCnt[v].first);
			}
		} else {
			valToCnt[v] = pair<int, int>(valToCnt.size(), 1);
			idToVal[valToCnt[v].first] = v;
		}
	}
	FirstUnique(vector<int>& nums) {
		for (const auto& v : nums) {
			_add(v);
		}
	}

	int showFirstUnique() {
		if (idToVal.empty()) return -1;
		return idToVal.begin()->second;
	}

	void add(int value) {
		_add(value);
	}

private:
	unordered_map<int, pair<int, int>> valToCnt;
	map<int, int> idToVal;
	virtual ~FirstUnique() {
	}
	FirstUnique &operator=(const FirstUnique &source);
	FirstUnique(const FirstUnique &);
};
