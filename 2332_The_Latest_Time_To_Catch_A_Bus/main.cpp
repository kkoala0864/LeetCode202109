#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> buses = {15, 16, 17, 7, 10, 20, 13, 12};
	vector<int> passengers = {18, 15, 11, 17, 12, 13, 14, 10, 19, 16};
	int capacity = 2;
	Solution *test = new Solution();
	cout << test->latestTimeCatchTheBus(buses, passengers, capacity) << endl;
	return 0;
}
