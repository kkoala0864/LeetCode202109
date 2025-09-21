#include <Solution.h>

int main(void) {
	//["MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"]
	//[[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
	vector<vector<int>> entries = {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
	int n = 3;
	MovieRentingSystem* test = new MovieRentingSystem(n, entries);
	auto result = test->search(1);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	test->rent(0, 1);
	test->rent(1, 2);
	auto res = test->report();
	for (const auto& val : res) {
		cout << "[" << val[0] << "," << val[1] << "] ";
	}
	cout << endl;
	test->drop(1, 2);
	result = test->search(2);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
