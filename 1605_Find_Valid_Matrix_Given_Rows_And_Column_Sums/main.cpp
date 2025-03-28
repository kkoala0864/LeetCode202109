#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> rs = {3, 8};
	vector<int> cs = {4, 7};
	Solution *test = new Solution();
	auto result = test->restoreMatrix(rs, cs);
	for (const auto &v : result) {
		for (const auto &c : v)
			cout << c << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}
