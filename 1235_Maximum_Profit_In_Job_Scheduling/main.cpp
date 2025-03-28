#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> s = {1, 2, 3, 4, 6};
	vector<int> e = {3, 5, 10, 6, 9};
	vector<int> p = {20, 20, 100, 70, 60};
	Solution *test = new Solution();
	cout << test->jobScheduling(s, e, p) << endl;
	cout << test->jobScheduling2(s, e, p) << endl;
	return 0;
}
