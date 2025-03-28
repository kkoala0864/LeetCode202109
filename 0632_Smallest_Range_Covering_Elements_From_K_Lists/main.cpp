#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1}};
	Solution *test = new Solution();
	auto result = test->smallestRange(input);
	cout << result[0] << " : " << result[1] << endl;
	return 0;
}
