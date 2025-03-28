#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> students = {1, 1, 1, 0, 0, 1};
	vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
	Solution *test = new Solution();
	cout << test->countStudents(students, sandwiches) << endl;
	return 0;
}
