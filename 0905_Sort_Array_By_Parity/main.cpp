#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 1, 2, 4};
	Solution *test = new Solution();
	auto result = test->sortArrayByParity(input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
