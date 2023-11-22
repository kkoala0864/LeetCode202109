#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
	Solution* test = new Solution();
	auto result = test->findDiagonalOrder(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

