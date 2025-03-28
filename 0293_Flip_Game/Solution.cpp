#include <Solution.h>
#include <iostream>

vector<string> Solution::generatePossibleNextMoves(string currentState) {
	vector<string> result;

	if (currentState.size() < 2)
		return result;
	int iter = 0;
	while (iter < currentState.size() - 1) {
		if (currentState[iter] == currentState[iter + 1] && currentState[iter] == '+') {
			string element = currentState;
			element[iter] = '-';
			element[iter + 1] = '-';
			result.emplace_back(element);
		}
		++iter;
	}
	return result;
}
