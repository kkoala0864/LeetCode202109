#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{7, 10}, {2, 4}};
	Solution *test = new Solution();
	cout << test->canAttendMeetings(input) << endl;
	cout << test->canAttendMeetings2(input) << endl;
	return 0;
}
