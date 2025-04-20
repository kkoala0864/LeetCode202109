#include <Solution.h>
#include <iostream>

long long Solution::calculateScore(vector<string>& instructions, vector<int>& values) {
	long long result = 0;
	vector<int> visited(instructions.size(), false);

	int idx = 0;

	while (idx < instructions.size() && !visited[idx]) {
		visited[idx] = true;
		if (instructions[idx] == "add") {
			result += values[idx];
			++idx;
		} else {
			idx += values[idx];
		}
	}
	return result;
}
