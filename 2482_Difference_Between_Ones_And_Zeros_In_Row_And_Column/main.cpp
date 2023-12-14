#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1,1},{1,0,1},{0,0,1}};
	Solution* test = new Solution();
	auto result = test->onesMinusZeros(input);
	for (const auto& v : result) {
		for (const auto& i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

