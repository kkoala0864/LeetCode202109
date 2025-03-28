#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"d1/", "d2/", "../", "d21/", "./"};
	Solution *test = new Solution();
	cout << test->minOperations(input) << endl;
	return 0;
}
