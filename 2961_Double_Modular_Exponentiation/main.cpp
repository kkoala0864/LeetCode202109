#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,3,3,10},{3,3,3,1},{6,1,1,4}};
	Solution* test = new Solution();
	auto result = test->getGoodIndices(input, 2);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

