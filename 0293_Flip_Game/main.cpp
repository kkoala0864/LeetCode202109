#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("++++");
	Solution *test = new Solution();
	vector<string> result = test->generatePossibleNextMoves(input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->generatePossibleNextMoves2(input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
