#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {1,2,3,0,0,0};
	vector<int> input2 = {2,5,6};
	Solution* test = new Solution();
	test->merge2(input1, 3, input2, 3);
	for (const auto& iter : input1) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

