#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
	Solution *test = new Solution();
	auto result = test->reconstructQueue(input);
	for (const auto &vec : input) {
		cout << "[" << vec[0] << " : " << vec[1] << "]" << endl;
	}
	cout << endl;
	result = test->reconstructQueue2(input);
	for (const auto &vec : input) {
		cout << "[" << vec[0] << " : " << vec[1] << "]" << endl;
	}
	cout << endl;
	return 0;
}
