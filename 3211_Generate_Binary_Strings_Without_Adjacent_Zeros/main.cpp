#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	auto result = test->validStrings(3);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
