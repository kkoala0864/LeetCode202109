#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{5,5},{4,6},{2,6}};
	Solution* test = new Solution();
	cout << test->scheduleCourse(input) << endl;
	return 0;
}

