#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<vector<int>>> data = {{{1,3},{6,7}},{{2,4}},{{2,5},{9,12}}};

	vector<vector<Interval>> input;
	for (const auto& d : data) {
		vector<Interval> vecInterval;
		for (const auto& t : d) {
			vecInterval.emplace_back(Interval(t[0], t[1]));
		}
		input.emplace_back(vecInterval);
	}
	Solution* test = new Solution();
	auto result = test->employeeFreeTime(input);
	for (const auto& t : result) {
		cout << t.start << ":" << t.end << endl;
	}
	return 0;
}

