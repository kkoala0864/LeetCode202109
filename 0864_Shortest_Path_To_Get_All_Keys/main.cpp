#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"@...a", ".###A", "b.BCc"};
	Solution *test = new Solution();
	cout << test->shortestPathAllKeys(input) << endl;
	return 0;
}
