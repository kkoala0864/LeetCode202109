#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::canWin2(string currentState) {
	if (currentState.size() < 2) return false;
	for (int i = 0 ; i < currentState.size()-1 ; ++i) {
		if (currentState[i] == currentState[i+1] && currentState[i] == '+') {
			currentState[i] = '-';
			currentState[i+1] = '-';
			if (!canWin2(currentState)) return true;
			currentState[i] = '+';
			currentState[i+1] = '+';
		}
	}
	return false;
}
