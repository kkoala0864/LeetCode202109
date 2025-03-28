#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {8, 1, 5, 2, 6};
	Solution *test = new Solution();
	cout << test->maxScoreSightseeingPair(input) << endl;
	return 0;
}
