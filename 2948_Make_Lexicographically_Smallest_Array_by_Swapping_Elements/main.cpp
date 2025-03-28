#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 5, 3, 9, 8};
	int limit = 2;
	Solution *test = new Solution();
	auto result = test->lexicographicallySmallestArray(input, limit);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
