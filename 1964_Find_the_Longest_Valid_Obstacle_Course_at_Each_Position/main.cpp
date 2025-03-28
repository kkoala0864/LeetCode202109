#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 1, 5, 6, 4, 2};
	Solution *test = new Solution();
	auto result = test->longestObstacleCourseAtEachPosition(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
