#include <Solution.h>

// pure output 1
// no input or ouput
// pure input 1/2
// left[i] + right[i] = machines[i] - average
// left[i] = -right[i-1];
// right[i] = machines[i] - average - left[i];

int Solution::findMinMoves(vector<int>& machines) {
	int sum = 0;
	for (const auto& v : machines) {
		sum += v;
	}
	int size = machines.size();
	if (sum % size) return -1;

	int average = sum / size;
	vector<int> left(size, 0), right(size, 0);
	right[0] = machines[0] - average;
	left.back() = machines.back() - average;

	for (int i = 1 ; i < size - 1 ; ++i) {
		left[i] = -right[i-1];
		right[i] = machines[i] - average - left[i];
	}

	int result = 0;
	for (int i = 0 ; i < size ; ++i) {
		int t = 0;
		if (left[i] > 0) t += left[i];
		if (right[i] > 0) t += right[i];
		result = max(result, t);
	}
	return result;
}
