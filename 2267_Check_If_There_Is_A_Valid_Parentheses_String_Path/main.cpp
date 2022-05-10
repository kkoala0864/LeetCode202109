#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'(','(','('},{')','(',')'},{'(','(',')'},{'(','(',')'}};
	Solution* test = new Solution();
	cout << test->hasValidPath(input) << endl;
	return 0;
}

