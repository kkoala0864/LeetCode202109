#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
	Solution* test = new Solution();
	cout << test->numMagicSquaresInside(input) << endl;
	return 0;
}

