#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{8,5},{8,7},{0,8},{0,5},{7,0},{5,0},{0,7},{8,0},{7,8}};
	Solution* test = new Solution();
	auto result = test->validArrangement(input);
	for (const auto& r : result) {
		for (const auto& v : r) cout << v << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}

