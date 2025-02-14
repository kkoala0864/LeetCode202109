#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> groups = {8,4,3,2,4};
	vector<int> elements = {4, 2};
	Solution* test = new Solution();
	auto result = test->assignElements(groups, elements);
	for (const auto& e : result) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

