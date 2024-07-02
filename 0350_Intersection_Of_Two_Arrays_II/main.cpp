#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {1,2,2,1};
	vector<int> input2 = {2,2};
	Solution* test = new Solution();
	auto result = test->intersect(input1, input2);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

