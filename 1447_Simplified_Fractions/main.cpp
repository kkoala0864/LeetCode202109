#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 4;
	Solution* test = new Solution();
	auto result = test->simplifiedFractions(n);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

