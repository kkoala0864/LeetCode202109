#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> start = {"ant", "act", "tack"};
	vector<string> target = {"tack", "act", "acti"};
	Solution *test = new Solution();
	cout << test->wordCount(start, target) << endl;
	return 0;
}
