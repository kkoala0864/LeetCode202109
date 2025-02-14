#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,7,3},{9,8,2},{4,5,6}};
	Solution* test = new Solution();
	auto result = test->sortMatrix(input);
	for (const auto& v : result) {
		for (const auto& val : v) {
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}

