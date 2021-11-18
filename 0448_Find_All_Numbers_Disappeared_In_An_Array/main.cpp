#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,1};
	Solution* test = new Solution();
	auto result = test->findDisappearedNumbers(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

