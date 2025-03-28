#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"What", "must", "be", "acknowledgment", "shall", "be"};
	Solution *test = new Solution();
	auto result = test->fullJustify(input, 16);
	for (const auto &r : result) {
		cout << "|" << r << "|" << endl;
	}
	return 0;
}
