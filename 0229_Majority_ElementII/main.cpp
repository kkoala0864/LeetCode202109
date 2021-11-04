#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,2,3,3,4,5,4,4,4,3};
	Solution* test = new Solution();
	vector<int> result = test->majorityElement(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

