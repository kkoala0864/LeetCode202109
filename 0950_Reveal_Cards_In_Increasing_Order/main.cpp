#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {17,13,11,2,3,5,7};
	Solution* test = new Solution();
	auto result = test->deckRevealedIncreasing(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

