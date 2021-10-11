#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

class MyCalendarTwo {
    public :
	    vector<vector<int>> first;
	    vector<vector<int>> twice;
	    MyCalendarTwo() {}
	    bool book(int start, int end) {
		    int cnt = 0;
		    for (const auto& iter : twice) {
			if ((iter[0] >= end) || (iter[1] <= start)) continue;
			else {
				return false;
			}
		    }

		    for (const auto& iter : first) {
			if((iter[0] >= end) || iter[1] <= start) continue;
			else {
				vector<int> tmp = {max(iter[0], start), min(iter[1], end)};
				twice.emplace_back(tmp);
			}
		    }
		    vector<int> tmp = {start , end};
		    first.emplace_back(tmp);
		    return true;
	    }
    private :
	    virtual ~MyCalendarTwo() {}
	    MyCalendarTwo& operator=(const MyCalendarTwo& source);
	    MyCalendarTwo(const MyCalendarTwo&);
};

