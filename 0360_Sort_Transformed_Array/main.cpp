#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-4, -2, 2, 4};
	Solution *test = new Solution();
	int a = -1, b = 3, c = 5;
	auto result = test->sortTransformedArray(input, a, b, c);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
