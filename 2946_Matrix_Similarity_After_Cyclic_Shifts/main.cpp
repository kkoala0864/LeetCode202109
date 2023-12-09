#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2,1,2},{5,5,5,5},{6,3,6,3}};
	Solution* test = new Solution();
	cout << test->areSimilar(input, 2) << endl;
	return 0;
}

