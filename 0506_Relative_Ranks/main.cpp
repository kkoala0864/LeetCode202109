#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,4,3,2,1};
	Solution* test = new Solution();
	auto result = test->findRelativeRanks(input);
	for (const auto& c : result) cout << c << " ";
	cout << endl;
	return 0;
}

