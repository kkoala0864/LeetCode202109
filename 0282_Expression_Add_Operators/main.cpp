#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string num = "105";
	int target = 5;
	Solution* test = new Solution();
	auto result = test->addOperators(num, target);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

