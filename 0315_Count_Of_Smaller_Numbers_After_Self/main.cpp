#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,2,6,1};
	Solution* test = new Solution();
	auto result = test->countSmaller(input);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	result = test->SegTree(input);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

