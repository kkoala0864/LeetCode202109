#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 12, 1, 2, 5, 50, 3};
	Solution *test = new Solution();
	cout << test->largestPerimeter(input) << endl;
	return 0;
}
