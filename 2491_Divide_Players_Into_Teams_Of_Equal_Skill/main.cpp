#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1000, 1000};
	Solution* test = new Solution();
	cout << test->dividePlayers(input) << endl;
	return 0;
}

