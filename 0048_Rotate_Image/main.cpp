#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1}};
	Solution* test = new Solution();
	test->rotate(input);
	for (auto n : input) {
		for (auto m : n) {
			cout << "\t" << m << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

