#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"dinnssoo","ddinso","ddiinnso","ddiinnssoo","ddiinso","dinsoo","ddiinsso","dinssoo","dinso"};
	Solution* test = new Solution();
	cout << test->expressiveWords("dddiiiinnssssssoooo", input) << endl;
	cout << test->expressiveWords2("dddiiiinnssssssoooo", input) << endl;
	cout << test->expressiveWords3("dddiiiinnssssssoooo", input) << endl;
	return 0;
}

