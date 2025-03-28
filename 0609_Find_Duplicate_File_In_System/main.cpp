#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
	Solution *test = new Solution();
	auto result = test->findDuplicate(input);
	for (const auto &r : result) {
		for (const auto &f : r) {
			cout << f << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
