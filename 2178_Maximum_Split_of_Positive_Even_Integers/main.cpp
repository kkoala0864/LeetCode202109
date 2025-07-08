#include <Solution.h>

int main(void) {
	int finalSum = 12;
	Solution *test = new Solution();
	auto result = test->maximumEvenSplit(finalSum);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
