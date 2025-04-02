#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {12, 6, 1, 2, 7};
	Solution *test = new Solution();
	cout << test->maximumTripletValue(input) << endl;
	return 0;
}
