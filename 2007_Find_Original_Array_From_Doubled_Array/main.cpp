#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 3, 4, 2, 6, 8};
	Solution *test = new Solution();
	vector<int> result = test->findOriginalArray(input);
	for (const auto &v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
