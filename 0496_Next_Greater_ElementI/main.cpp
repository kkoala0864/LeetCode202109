#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {4,1,2};
	vector<int> input2 = {1,3,4,2};
	Solution* test = new Solution();
	vector<int> result = test->nextGreaterElement2(input1, input2);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

