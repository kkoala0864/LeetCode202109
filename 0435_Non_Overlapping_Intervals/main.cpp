#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{-52, 31}, {-73, -26}, {82, 97}, {-65, -11}, {-62, -49}, {95, 99}, {58, 95}, {-31, 49}, {66, 98}, {-63, 2}, {30, 47}, {-40, -26}};
	Solution *test = new Solution();
	cout << test->eraseOverlapIntervals(input) << endl;
	cout << test->eraseOverlapIntervals2(input) << endl;
	return 0;
}
