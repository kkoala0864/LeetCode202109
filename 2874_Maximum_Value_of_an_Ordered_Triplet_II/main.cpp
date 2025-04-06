#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,10,3,4,19};
	Solution *test = new Solution();
	cout << test->maximumTripletValue(input) << endl;
	return 0;
}
