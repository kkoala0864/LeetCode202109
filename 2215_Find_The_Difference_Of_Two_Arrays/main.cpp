#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {1, 2, 3, 3};
	vector<int> input2 = {1, 1, 2, 2};
	Solution *test = new Solution();
	auto result = test->findDifference(input1, input2);
	for (const auto &r : result) {
		for (const auto &v : r)
			cout << v << " ";
		cout << endl;
	}
	return 0;
}
