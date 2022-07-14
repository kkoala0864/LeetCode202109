#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {1,7,11};
	vector<int> input2 = {2,4,6};
	Solution* test = new Solution();
	auto result = test->kSmallestPairs(input1, input2, 3);
	for (const auto& vec : result) {
		for (const auto& v : vec) {
			cout << v << " ";
		}
		cout << endl;
	}
	return 0;
}

