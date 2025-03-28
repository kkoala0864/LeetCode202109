#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"a==b", "b!=a"};
	Solution *test = new Solution();
	cout << test->equationsPossible(input) << endl;
	return 0;
}
