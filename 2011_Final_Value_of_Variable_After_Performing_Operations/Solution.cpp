#include <Solution.h>

int Solution::finalValueAfterOperations(vector<string>& operations) {
	int result = 0;
	for (const auto& o : operations) {
		if (o[0] == 'X') {
			result += o.back() == '-' ? -1 : 1;
		} else {
			result += o[0] == '-' ? -1 : 1;
		}
	}
	return result;
}
