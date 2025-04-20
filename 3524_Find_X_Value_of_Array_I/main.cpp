#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,3,4,5};
	int k = 3;
	Solution *test = new Solution();
	auto result = test->resultArray(input, k);
	for (const auto&  v: result) cout << v << " ";
	cout << endl;
	return 0;
}
