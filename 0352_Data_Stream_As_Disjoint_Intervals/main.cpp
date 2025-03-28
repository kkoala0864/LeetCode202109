#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {6, 6, 0, 4, 8, 7, 6, 4, 7, 5};
	SummaryRanges *test = new SummaryRanges();
	for (auto &iter : input) {
		test->addNum(iter);
		auto result = test->getIntervals();
		for (const auto &val : result) {
			cout << "[" << val[0] << ":" << val[1] << "] ";
		}
		cout << endl;
		cout << endl;
	}
	return 0;
}
