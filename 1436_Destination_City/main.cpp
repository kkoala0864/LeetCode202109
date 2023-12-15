#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<string>> input = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
	Solution* test = new Solution();
	cout << test->destCity(input) << endl;
	return 0;
}

