#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> regular = {11, 5, 13};
	vector<int> express = {7, 10, 6};
	int expressCost = 3;
	Solution *test = new Solution();
	auto result = test->minimumCosts(regular, express, expressCost);
	for (const auto &l : result) {
		cout << l << " ";
	}
	cout << endl;
	return 0;
}
