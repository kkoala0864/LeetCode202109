#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,1,1},{1,0,1},{1,1,1}};
	Solution* test = new Solution();
	auto result = test->imageSmoother(input);
	for (const auto& v : result) {
		for (const auto& c : v) cout << c << " ";
		cout << endl;
	}
	return 0;
}

