#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,30},{5,10},{15,20}};
	Solution* test = new Solution();
	cout << test->minMeetingRooms(input) << endl;
	cout << test->minMeetingRooms2(input) << endl;
	cout << test->minMeetingRooms3(input) << endl;
	return 0;
}

