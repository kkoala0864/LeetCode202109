#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 5, 4, 3, 6};
	Solution *test = new Solution();
	auto result = test->maximumLengthOfRanges(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
