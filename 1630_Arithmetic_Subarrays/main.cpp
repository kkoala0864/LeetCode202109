#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
	vector<int> l = {0,1,6,4,8,7};
	vector<int> r = {4,4,9,7,9,10};
	Solution* test = new Solution();
	auto result = test->checkArithmeticSubarrays(input, l, r);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

