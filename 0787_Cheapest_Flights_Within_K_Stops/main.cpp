#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
	int n = 4;
	int src = 0;
	int dst = 3;
	int k = 1;
	Solution *test = new Solution();
	cout << test->findCheapestPrice(n, flights, src, dst, k) << endl;
	return 0;
}
