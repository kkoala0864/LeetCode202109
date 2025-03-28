#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
	Solution *test = new Solution();
	vector<int> result = test->getModifiedArray(5, updates);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
