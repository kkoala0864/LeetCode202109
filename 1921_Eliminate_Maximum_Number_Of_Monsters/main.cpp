#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> dist = {3, 2, 4};
	vector<int> speed = {5, 3, 2};
	Solution *test = new Solution();
	cout << test->eliminateMaximum(dist, speed) << endl;
	return 0;
}
