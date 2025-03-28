#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string start = "RXXLRXRXL";
	string result = "XRLXXRRLX";
	Solution *test = new Solution();
	cout << test->canTransform(start, result) << endl;
	return 0;
}
