#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	bool canAttendMeetings(vector<vector<int>>& intervals);
	bool canAttendMeetings2(vector<vector<int>>& intervals);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

