#include <vector>
#include <iostream>
#include <set>

using std::vector;
using std::set;
using std::pair;

class SummaryRanges {
    public :
	SummaryRanges() {}

	void addNum(int val) {
		pair<int, int> cur = pair<int, int>(val, val);
		auto it = lower_bound(_s.begin(), _s.end(), cur);
		if (it != _s.end() && it->first == val) return;
		if (it != _s.begin()) {
			auto pre = it;
			--pre;
			if (pre->second >= val) return;
			if (val - pre->second == 1) {
				cur.first = pre->first;
				_s.erase(pre);
			}
		}
		if (it != _s.end() && (it->first - val) == 1) {
			cur.second = it->second;
			_s.erase(it);
		}
		_s.emplace(cur);
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> result;
		for (auto& val : _s) {
			result.push_back({val.first, val.second});
		}
		return result;
	}
    private :
	set<pair<int, int>> _s;
        virtual ~SummaryRanges() {}
        SummaryRanges& operator=(const SummaryRanges& source);
        SummaryRanges(const SummaryRanges&);
};

