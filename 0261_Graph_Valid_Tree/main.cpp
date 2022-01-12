#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{1,2},{2,3},{1,3},{1,4}};
	Solution* test = new Solution();
	cout << test->validTree(5, input) << endl;
	cout << test->validTree2(5, input) << endl;
	cout << test->validTree3(5, input) << endl;
	return 0;
}

