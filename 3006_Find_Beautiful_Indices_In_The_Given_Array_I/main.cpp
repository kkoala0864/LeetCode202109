#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "isawsquirrelnearmysquirrelhouseohmy";
	string a = "my";
	string b = "squirrel";
	int k = 15;
	Solution *test = new Solution();
	auto result = test->beautifulIndices(s, a, b, k);
	for (const auto &idx : result) {
		cout << idx << " ";
	}
	cout << endl;
	return 0;
}
