#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "(name)is(age)yearsold";
	vector<vector<string>> knowledge = {{"name", "bob"}, {"age", "two"}};
	Solution *test = new Solution();
	cout << test->evaluate(input, knowledge) << endl;
	return 0;
}
