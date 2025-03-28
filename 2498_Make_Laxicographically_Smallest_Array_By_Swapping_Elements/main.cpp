#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 7, 28, 19, 10};
	Solution *test = new Solution();
	auto result = test->lexicographicallySmallestArray(input, 3);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
