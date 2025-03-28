#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> dif = {23, 30, 35, 35, 43, 46, 47, 81, 83, 98};
	vector<int> profit = {8, 11, 11, 20, 33, 37, 60, 72, 87, 95};
	vector<int> worker = {95, 46, 47, 97, 11, 35, 99, 56, 41, 92};
	Solution *test = new Solution();
	cout << test->maxProfitAssignment(dif, profit, worker) << endl;
	return 0;
}
