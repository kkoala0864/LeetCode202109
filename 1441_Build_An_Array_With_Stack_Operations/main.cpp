#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> target = {1,3};
	Solution* test = new Solution();
	auto result = test->buildArray(target, 3);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

