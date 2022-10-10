#include <unordered_map>
#include <algorithm>
#include <map>

using std::max;
using std::map;

class MyCalendarThree {
    public :
	MyCalendarThree() {}

	int book(int start, int end) {
		int cur = 0, result = 0;
		++_m[start];
		--_m[end];
		for (const auto& e : _m) {
			cur += e.second;
			result = max(result, cur);
		}
		return result;
	}
    private :
	map<int, int> _m;
        virtual ~MyCalendarThree() {}
        MyCalendarThree& operator=(const MyCalendarThree& source);
        MyCalendarThree(const MyCalendarThree&);
};

