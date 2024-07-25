#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {110, 100, 0};
	Solution* test = new Solution();
	auto result = test->sortArray(input);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

