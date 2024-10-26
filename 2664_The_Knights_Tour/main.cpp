#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int m = 3, n = 4, r = 0, c = 3;
	Solution* test = new Solution();
	auto result = test->tourOfKnight(m, n, r, c);
	for (const auto& v : result) {
		for (const auto& c : v) cout << c << " ";
		cout << endl;
	}
	return 0;
}

