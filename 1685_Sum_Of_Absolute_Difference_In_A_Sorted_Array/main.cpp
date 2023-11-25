#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,4,6,8,10};
	Solution* test = new Solution();
	auto result = test->getSumAbsoluteDifferences(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

