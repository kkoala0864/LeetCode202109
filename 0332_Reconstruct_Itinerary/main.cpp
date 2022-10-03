#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<string>> input = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
	Solution* test = new Solution();
	vector<string> result = test->findItinerary(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->findItinerary4(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

