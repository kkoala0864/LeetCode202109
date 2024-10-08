#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> heroes = {1,4,2};
	vector<int> monsters = {1,1,5,2,3};
	vector<int> coins = {2,3,4,5,6};
	Solution* test = new Solution();
	auto result = test->maximumCoins(heroes, monsters, coins);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

