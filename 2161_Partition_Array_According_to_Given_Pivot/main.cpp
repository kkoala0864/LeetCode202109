#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {9,12,5,10,14,3,10};
	int pivot = 10;
	Solution* test = new Solution();
	auto result = test->pivotArray(input, pivot);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

