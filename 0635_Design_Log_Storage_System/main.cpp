#include <Solution.h>

int main(void) {
	//["LogSystem", "put", "put", "put", "retrieve", "retrieve"]
	//[[], [1, "2017:01:01:23:59:59"], [2, "2017:01:01:22:59:59"], [3, "2016:01:01:00:00:00"], ["2016:01:01:01:01:01", "2017:01:01:23:00:00", "Year"], ["2016:01:01:01:01:01", "2017:01:01:23:00:00", "Hour"]]
	LogSystem *test = new LogSystem();
	test->put(1, "2017:01:01:23:59:59");
	test->put(2, "2017:01:01:22:59:59");
	test->put(3, "2016:01:01:00:00:00");
	auto result = test->retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Year");
	for (auto &i : result) {
		cout << i << " ";
	}
	cout << endl;
	result = test->retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Hour");
	for (auto &i : result) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
