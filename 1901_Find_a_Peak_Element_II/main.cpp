#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{70,50,40,30,20},{100,1,2,3,4}};
	Solution *test = new Solution();
	auto result = test->findPeakGrid(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
