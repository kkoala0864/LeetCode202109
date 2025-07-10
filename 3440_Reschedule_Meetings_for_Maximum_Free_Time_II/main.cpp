#include <Solution.h>

int main(void) {
	int eventTime = 10;
	vector<int> startTime = {0, 3, 7, 9};
	vector<int> endTime = {1, 4, 8, 10};
	Solution *test = new Solution();
	cout << test->maxFreeTime(eventTime, startTime, endTime) << endl;
	return 0;
}
