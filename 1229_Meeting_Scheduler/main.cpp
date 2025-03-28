#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input1 = {{10, 50}, {60, 120}, {140, 210}};
	vector<vector<int>> input2 = {{0, 15}, {60, 70}};
	Solution *test = new Solution();
	auto result = test->minAvailableDuration(input1, input2, 8);
	for (auto &val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
