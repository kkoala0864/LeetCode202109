#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int eventTime = 10;
	int k = 1;
	vector<int> startTime = {0, 2, 9};
	vector<int> endTime = {1, 4, 10};
	Solution *test = new Solution();
	cout << test->maxFreeTime(eventTime, k, startTime, endTime) << endl;
	return 0;
}
