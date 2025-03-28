#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
	Solution *test = new Solution();
	auto result = test->findAndReplacePattern(input, "abb");
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
