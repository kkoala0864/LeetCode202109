#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2,3},{2,5,7},{3,5,1}};
	vector<int> query = {5,6,2};
	Solution* test = new Solution();
	auto result = test->maxPoints(input, query);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

