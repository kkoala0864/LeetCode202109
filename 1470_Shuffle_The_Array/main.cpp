#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,5,1,3,4,7};
	Solution* test = new Solution();
	auto result = test->shuffle(input, 3);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

