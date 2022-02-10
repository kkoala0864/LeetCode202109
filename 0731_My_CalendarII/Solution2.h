#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

class MyCalendarTwo {
    public :
	    vector<vector<int>> once;
	    vector<vector<int>> twice;
	    MyCalendarTwo() {}
	    bool book(int start, int end) {
		    for (const auto& iter : twice) {
			if (start >= iter[1] || end <= iter[0]) {
				continue;
			} else {
				return false;
			}
		    }
		    for (const auto& iter : once) {
			if (start >= iter[1] || end <= iter[0]) {
				continue;
			} else {
				twice.push_back({max(start, iter[0]), min(end, iter[1])});
			}
		    }
		    once.push_back({start, end});
		    return true;
	    }
    private :
	    virtual ~MyCalendarTwo() {}
	    MyCalendarTwo& operator=(const MyCalendarTwo& source);
	    MyCalendarTwo(const MyCalendarTwo&);
};

