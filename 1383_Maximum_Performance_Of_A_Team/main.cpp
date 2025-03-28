#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> speed = {2, 10, 3, 1, 5, 8};
	vector<int> efficiency = {5, 4, 3, 9, 7, 2};
	Solution *test = new Solution();
	cout << test->maxPerformance(6, speed, efficiency, 2) << endl;
	return 0;
}
