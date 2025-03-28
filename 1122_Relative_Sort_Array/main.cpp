#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {2, 21, 43, 38, 0, 42, 33, 7, 24, 13, 12, 27, 12, 24, 5, 23, 29, 48, 30, 31};
	vector<int> input2 = {2, 42, 38, 0, 43, 21};
	Solution *test = new Solution();
	auto result = test->relativeSortArray(input1, input2);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
