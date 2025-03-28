#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"tars", "rats", "arts", "star"};
	Solution *test = new Solution();
	cout << test->numSimilarGroups(input) << endl;
	return 0;
}
