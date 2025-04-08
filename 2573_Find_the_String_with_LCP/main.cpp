#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};
	Solution *test = new Solution();
	cout << test->findTheString(input) << endl;
	return 0;
}
