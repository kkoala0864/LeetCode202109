#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "RDD";
	Solution* test = new Solution();
	cout << test->predictPartyVictory(input) << endl;
	return 0;
}

