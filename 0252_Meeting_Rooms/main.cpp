#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,30},{5,10},{15,20}};
	Solution* test = new Solution();
	cout << test->canAttendMeetings(input) << endl;
	return 0;
}

