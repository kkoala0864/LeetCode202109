#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int height = 100;
	int width = 10;
	vector<int> input = {1,2,3,4,5,6,7,8,9,10};
	Solution *test = new Solution();
	cout << test->buildWall(height, width, input) << endl;
	return 0;
}
