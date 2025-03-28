#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

long long Solution::dividePlayers(vector<int> &skill) {
	long long sum = 0;
	vector<long long> m(1001, 0);
	for (const auto &s : skill) {
		sum += s;
		++m[s];
	}
	long long average = sum / (skill.size() / 2);
	if (average > 2000)
		return -1;

	long long result = 0;
	long long cnt = 0;
	for (long long i = 1; i <= (average / 2); ++i) {
		if (m[i] == 0)
			continue;
		int op = average - i;
		if (op > 1000)
			return -1;

		if (i == op) {
			if (m[i] & 1)
				return -1;
			result += ((i * op) * (m[i] / 2));
			cnt += (m[i] / 2);
		} else {
			if (m[i] != m[op])
				return -1;
			result += ((i * op) * m[i]);
			cnt += m[i];
		}
	}
	return cnt == (skill.size() / 2) ? result : -1;
}
