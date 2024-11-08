#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,1,1,3};
	int k = 2;
	Solution* test = new Solution();
	auto result = test->getMaximumXor(input, k);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

