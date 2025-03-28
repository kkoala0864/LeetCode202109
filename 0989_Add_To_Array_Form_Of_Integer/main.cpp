#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 1, 5};
	Solution *test = new Solution();
	auto result = test->addToArrayForm(input, 80);

	for (const auto &v : result)
		cout << v;
	cout << endl;
	return 0;
}
