#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 1, 0, 0, 0},
	                             {1, 1, 1, 1, 0},
	                             {1, 0, 0, 0, 0},
	                             {1, 1, 0, 0, 0},
	                             {1, 1, 1, 1, 1}};
	Solution *test = new Solution();
	auto result = test->kWeakestRows(input, 3);
	for (const auto &it : result) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}
