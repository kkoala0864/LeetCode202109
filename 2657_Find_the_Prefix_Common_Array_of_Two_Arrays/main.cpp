#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> A = {1,3,2,4};
	vector<int> B = {3,1,2,4};
	Solution* test = new Solution();
	auto result = test->findThePrefixCommonArray(A, B);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

