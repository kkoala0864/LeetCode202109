#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	//["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
	//[[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
	vector<int> persons({0, 1, 1, 0, 0, 1, 0});
	vector<int> times({0, 5, 10, 15, 20, 25, 30});
	TopVotedCandidate* test = new TopVotedCandidate(persons, times);
	cout << test->q(3) << endl;
	cout << test->q(12) << endl;
	cout << test->q(25) << endl;
	cout << test->q(15) << endl;
	cout << test->q(24) << endl;
	cout << test->q(8) << endl;

	return 0;
}
