#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"MMM", "PGM", "GP"};
	vector<int> travel = {3, 10};
	Solution *test = new Solution();
	cout << test->garbageCollection(input, travel) << endl;
	return 0;
}
