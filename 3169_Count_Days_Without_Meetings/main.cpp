#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{5,7},{1,3},{9,10}};
	int n = 10;
	Solution* test = new Solution();
	cout << test->countDays(n, input) << endl;
	return 0;
}

