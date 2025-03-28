#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::leastInterval(vector<char> &tasks, int n) {
	vector<int> frequency(26, 0);
	for (const auto &t : tasks)
		++frequency[t - 'A'];

	sort(frequency.begin(), frequency.end(), std::greater<int>());
	int fMax = frequency[0];
	int i = 1;
	while (i < frequency.size() && frequency[i] == fMax)
		++i;

	return max((fMax - 1) * (n + 1) + i, (int)tasks.size());
}
