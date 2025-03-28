#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "110";
	Solution *test = new Solution();
	auto result = test->minOperations(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
