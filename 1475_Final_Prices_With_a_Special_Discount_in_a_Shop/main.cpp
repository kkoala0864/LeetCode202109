#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {8,4,6,2,3};
	Solution* test = new Solution();
	auto result = test->finalPrices(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

