#include <Solution.h>
#include <iostream>

bool Solution::canWin(string currentState) {
	int size = currentState.size();
	if (size == 0) return false;

	bool find = false;
	for (int i = 0 ; i < size-1 ; ++i) {
		if (currentState[i] == currentState[i+1] && currentState[i] == '+') {
			find = true;
			currentState[i] = '-';
			currentState[i+1] = '-';
			if (!canWin(currentState)) {
				return true;
			}
			currentState[i] = '+';
			currentState[i+1] = '+';
		}
	}
	return false;
}
