#include <set>

using std::pair;
using std::set;

class MyCalendar {
    public :
	    MyCalendar() {}

	    bool book(int start, int end) {
		    for (const auto& e : _m) {
			if (e.first > (end-1)) break;
			else if (e.second < start) continue;
			else return false;
		    }
		    _m.emplace(pair<int, int>(start, end-1));
		    return true;
	    }
    private :
	    set<pair<int, int>> _m;
        virtual ~MyCalendar() {}
        MyCalendar& operator=(const MyCalendar& source);
        MyCalendar(const MyCalendar&);
};

