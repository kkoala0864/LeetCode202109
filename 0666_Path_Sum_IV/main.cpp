#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {111, 217, 221, 315, 415};
	Solution *test = new Solution();
	cout << test->pathSum(input) << endl;
	return 0;
}
