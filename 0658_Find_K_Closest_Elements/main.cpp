#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,1,1,10,10,10};
	Solution* test = new Solution();
	auto result = test->findClosestElements(input, 1, 9);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

