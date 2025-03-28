#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
	vector<int> numbers = {991, 338, 38};
	Solution *test = new Solution();
	auto result = test->sortJumbled(mapping, numbers);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
