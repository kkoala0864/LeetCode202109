#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	vector<string> ret = test->findStrobogrammatic(4);
	for (const auto &iter : ret) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
