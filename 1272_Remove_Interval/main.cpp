#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{-5,-4},{-3,-2},{1,2},{3,5},{8,9}};
	vector<int> remove = {-1, 4};
	Solution* test = new Solution();
	auto result = test->removeInterval(input, remove);
	for (const auto& v : result) {
		cout << "[" << v[0] << " : " << v[1] << "]" << endl;
	}
	return 0;
}

