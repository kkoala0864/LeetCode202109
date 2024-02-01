#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,3,5,1,3};
	Solution* test = new Solution();
	auto result = test->kidsWithCandies(input, 3);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

