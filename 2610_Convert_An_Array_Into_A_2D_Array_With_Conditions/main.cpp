#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,4,1,2,3,1};
	Solution* test = new Solution();
	auto result = test->findMatrix(input);
	for (const auto& v : result) {
		for (const auto& i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

