#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<double> prob = {0.5, 0.5, 0.5, 0.5, 0.5};
	Solution *test = new Solution();
	cout << test->probabilityOfHeads(prob, 0) << endl;
	return 0;
}
