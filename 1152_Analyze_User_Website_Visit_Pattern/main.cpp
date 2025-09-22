#include <Solution.h>

int main(void) {
	vector<string> username = {"joe","joe","joe","james","james","james","james","mary","mary","mary"};
	vector<int> timestamp = {1,2,3,4,5,6,7,8,9,10};
	vector<string> website = {"home","about","career","home","cart","maps","home","home","about","career"};
	Solution* test = new Solution();
	vector<string> result = test->mostVisitedPattern(username, timestamp, website);
	for (const auto& str : result) {
		cout << str << " ";
	}
	cout << endl;
	return 0;
}
