#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{48, 49}, {22, 30}, {13, 31}, {31, 46}, {37, 46}, {32, 36}, {25, 36}, {49, 50}, {24, 34}, {6, 41}};
	int k = 4;
	Solution *test = new Solution();
	cout << test->mostBooked(k, input) << endl;
	return 0;
}
