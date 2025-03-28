#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"00", "01"};
	Solution *test = new Solution();
	cout << test->findDifferentBinaryString(input) << endl;
	return 0;
}
