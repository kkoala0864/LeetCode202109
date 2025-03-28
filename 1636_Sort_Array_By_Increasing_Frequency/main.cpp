#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 1, 2, 2, 2, 3};
	Solution *test = new Solution();
	auto result = test->frequencySort(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
