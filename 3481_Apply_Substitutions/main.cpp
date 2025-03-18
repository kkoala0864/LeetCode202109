#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<string>> replacements = {{"A","bce"},{"B","ace"},{"C","abc%B%"}};
	string input = "%A%_%B%_%C%";
	Solution* test = new Solution();
	cout << test->applySubstitutions(replacements, input) << endl;
	return 0;
}

