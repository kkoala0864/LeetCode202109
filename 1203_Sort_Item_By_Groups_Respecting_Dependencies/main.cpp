#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> groups = {0,0,2,1,0};
	vector<vector<int>> bi = {{3},{},{},{},{1,3,2}};
	Solution* test = new Solution();
	auto result = test->sortItems(5, 3, groups, bi);
	for (const auto& r : result) {
		cout << r << " ";
	}
	cout << endl;
	return 0;
}

