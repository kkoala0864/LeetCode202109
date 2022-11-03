#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'X','O','O','X','X','X','O','X','O','O'},{'X','O','X','X','X','X','X','X','X','X'},{'X','X','X','X','O','X','X','X','X','X'},{'X','O','X','X','X','O','X','X','X','O'},{'O','X','X','X','O','X','O','X','O','X'},{'X','X','O','X','X','O','O','X','X','X'},{'O','X','X','O','O','X','O','X','X','O'},{'O','X','X','X','X','X','O','X','X','X'},{'X','O','O','X','X','O','X','X','O','O'},{'X','X','X','O','O','X','O','X','X','O'}};
	Solution* test = new Solution();
	for (const auto& iter : input) {
		for (const auto& it : iter) {
			cout << it << " ";
		}
		cout << endl;
	}
	cout << endl;
	test->solve2(input);
	for (const auto& iter : input) {
		for (const auto& it : iter) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}

