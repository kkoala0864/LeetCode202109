#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "Mg(H2O)N";
	Solution* test = new Solution();
	cout << test->countOfAtoms(input) << endl;
	return 0;
}

