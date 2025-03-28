#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4, 5, 10, 6, 11, 17, 4, 11, 1, 3};
	int k = 1;
	Solution *test = new Solution();
	auto result = test->maxSumOfThreeSubarrays(input, k);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
