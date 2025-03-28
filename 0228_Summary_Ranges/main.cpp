#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0, 1, 2, 4, 5, 7};
	Solution *test = new Solution();
	vector<string> result = test->summaryRanges(input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
