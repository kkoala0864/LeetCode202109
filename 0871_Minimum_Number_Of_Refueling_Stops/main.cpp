#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution* test = new Solution();
	/*
	vector<vector<int>> input = {{53850,170579},{144779,184975},{285970,250699},{551380,63687},{563517,183875},{652555,16550},{720886,328338},{821172,7541},{941712,180342},{978151,58191}};
	cout << test->minRefuelStops(1000000, 70768, input) << endl;
	*/
	vector<vector<int>> input = {{10,60},{20,30},{30,30},{60,40}};
	cout << test->minRefuelStops(100, 10, input) << endl;
	return 0;
}

