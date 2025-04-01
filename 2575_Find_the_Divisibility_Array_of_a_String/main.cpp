#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "998244353";
	int m = 3;
	Solution *test = new Solution();
	auto result = test->divisibilityArray(input, m);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
