#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "AAAABBBB";
	Solution* test = new Solution();
	cout << test->winnerOfGame(input) << endl;
	return 0;
}

