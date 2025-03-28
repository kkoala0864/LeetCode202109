#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {2, 5, 6, 4, 4, 0};
	vector<int> input2 = {7, 3, 8, 0, 6, 5, 7, 6, 2};
	int k = 15;
	Solution *test = new Solution();
	auto result = test->maxNumber(input1, input2, k);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
