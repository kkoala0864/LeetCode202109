#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<string>> equation = {{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}};
	vector<double> values = {3.0, 4.0, 5.0, 6.0};
	vector<vector<string>> quries = {{"x5", "x2"}};
	Solution *test = new Solution();
	auto result = test->calcEquation(equation, values, quries);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->calcEquation2(equation, values, quries);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
