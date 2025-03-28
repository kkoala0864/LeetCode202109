#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<string>> input = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}};
	Solution *test = new Solution();
	vector<vector<string>> result = test->accountsMerge(input);
	for (const auto &person : result) {
		for (const auto &info : person) {
			cout << info << " ";
		}
		cout << endl;
	}
	cout << endl;
	result = test->accountsMerge(input);
	for (const auto &person : result) {
		for (const auto &info : person) {
			cout << info << " ";
		}
		cout << endl;
	}
	return 0;
}
