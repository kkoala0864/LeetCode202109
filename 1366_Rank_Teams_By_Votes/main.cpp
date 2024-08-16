#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"ABC","ACB","ABC","ACB","ACB"};
	Solution* test = new Solution();
	cout << test->rankTeams(input) << endl;
	return 0;
}

