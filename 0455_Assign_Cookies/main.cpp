#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> g = {1,2,3};
	vector<int> s = {1,2};
	Solution* test = new Solution();
	cout << test->findContentChildren(g, s) << endl;
	return 0;
}

