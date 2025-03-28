#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5, 1, 2, 3, 10};
	Solution *test = new Solution();
	auto result = test->canSeePersonsCount(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
