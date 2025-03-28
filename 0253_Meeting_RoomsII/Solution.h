#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int minMeetingRooms(vector<vector<int>> &intervals);
	int minMeetingRooms2(vector<vector<int>> &intervals);
	int minMeetingRooms3(vector<vector<int>> &intervals);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
