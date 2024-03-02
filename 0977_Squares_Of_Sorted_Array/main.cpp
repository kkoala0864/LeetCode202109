#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-4,-1,0,3,10};
	Solution* test = new Solution();
	auto result = test->sortedSquares(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

