#include <vector>

using std::vector;
class Interval {
	public:
		int start;
		int end;

		Interval() {}

		Interval(int _start, int _end) {
			start = _start;
			end = _end;
		}
};

class Solution {
    public :
        Solution() {}
	vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

