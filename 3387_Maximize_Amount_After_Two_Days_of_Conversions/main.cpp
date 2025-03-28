#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string initialCurrency = "DOO";
	vector<vector<string>> pairs1 = {{"QL", "W"}, {"DOO", "QL"}, {"DOO", "P"}};
	vector<double> rates1 = {3.0, 6.7, 3.2};

	vector<vector<string>> pairs2 = {{"P", "QL"}, {"QL", "DOO"}, {"W", "P"}};
	vector<double> rates2 = {5.2, 1.8, 5.6};
	Solution *test = new Solution();
	cout << test->maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2) << endl;
	return 0;
}
