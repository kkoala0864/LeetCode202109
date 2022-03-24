#include <Solution.h>
#include <iostream>

vector<string> Solution::generatePossibleNextMoves2(string currentState) {
	vector<string> result;
	for (int i = 0 ; i < currentState.size() - 1 ; ++i) {
		if (currentState[i] == '+' && currentState[i+1] == '+') {
			string local = currentState;
			local[i] = '-';
			local[i+1] = '-';
			result.emplace_back(local);
		}
	}
	return result;
}
