#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {7, 6, 9, 6, 9, 6, 9, 7};
	Solution *test = new Solution();
	cout << test->minJumps(input) << endl;
	return 0;
}
