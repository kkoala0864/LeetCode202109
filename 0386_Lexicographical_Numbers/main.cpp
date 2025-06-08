#include <Solution.h>

int main(void) {
	Solution *test = new Solution();
	vector<int> result = test->lexicalOrder(13);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
