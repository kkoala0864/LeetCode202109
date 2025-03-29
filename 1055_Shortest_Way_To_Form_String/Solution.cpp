#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::shortestWay(string source, string target) {
	int result = 1;
	size_t idx = -1;
	for (int i = 0; i < target.size(); ++i) {
		idx = source.find(target[i], idx + 1);
		if (idx != std::string::npos) {
			continue;
		} else {
			idx = source.find(target[i]);
			if (idx == std::string::npos) {
				return -1;
			} else {
				++result;
			}
		}
	}
	return result;
}
