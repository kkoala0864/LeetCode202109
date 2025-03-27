#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
	Solution* test = new Solution();
	auto result = test->getSkyline(input);
	for (const auto& v : result) {
		cout << v[0] << " : " << v[1] << endl;
	}
	return 0;
}

