#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "AAAAAAAAAAA";
	Solution* test = new Solution();
	vector<string> result = test->findRepeatedDnaSequences(s);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

