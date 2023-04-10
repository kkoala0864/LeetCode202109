#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> spells = {5,1,3};
	vector<int> potions = {1,2,3,4,5};
	Solution* test = new Solution();
	auto result = test->successfulPairs(spells, potions, 7);
	for (const auto& c : result) cout << c << " ";
	cout << endl;
	return 0;
}

