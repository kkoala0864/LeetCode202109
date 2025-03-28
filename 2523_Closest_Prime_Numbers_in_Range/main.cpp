#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int l = 628853, r = 801856;
	Solution *test = new Solution();
	auto result = test->closestPrimes(l, r);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
