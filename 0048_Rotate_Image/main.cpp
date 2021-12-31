#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2,3},{4,5,6},{7,8,9}};
	Solution* test = new Solution();
	test->rotate3(input);
	for (auto n : input) {
		for (auto m : n) {
			cout << m << " ";
		}
		cout << endl;
	}
	return 0;
}

