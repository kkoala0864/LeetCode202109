#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,3,4,5};
	Solution* test = new Solution();
	auto result = test->findClosestElements(input, 4, -1);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	result = test->findClosestElements2(input, 4, -1);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

