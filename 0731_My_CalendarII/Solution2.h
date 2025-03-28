#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::pair;
using std::vector;

class MyCalendarTwo {
public:
	MyCalendarTwo() {
	}

	bool book(int start, int end) {
		for (const auto &t : twice) {
			if (t.first >= end || t.second <= start)
				continue;
			return false;
		}

		for (const auto &t : first) {
			if (t.first >= end || t.second <= start)
				continue;
			twice.push_back({max(t.first, start), min(t.second, end)});
		}
		first.push_back({start, end});
		return true;
	}

private:
	vector<pair<int, int>> first;
	vector<pair<int, int>> twice;
	virtual ~MyCalendarTwo() {
	}
	MyCalendarTwo &operator=(const MyCalendarTwo &source);
	MyCalendarTwo(const MyCalendarTwo &);
};
