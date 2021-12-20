#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,8,-10,23,19,-4,-14,27};
	Solution* test = new Solution();
	auto result = test->minimumAbsDifference(input);
	for (const auto& iter : result) {
		cout << iter[0] << " : " << iter[1] << endl;
	}
	return 0;
}

