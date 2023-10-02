#include <Solution.h>
#include <iostream>

using namespace std;

bool Solution::winnerOfGame(string colors) {
	int cntA = 1, cntB = 1;
	int rA = 0, rB = 0;
	int size = colors.size();
	int iter = 0;
	for (int i = 0 ; i < size ; ++i) {
		iter = i+1;
		while (iter < size && (colors[i] == colors[iter])) {
			if (colors[iter] == 'A') ++cntA;
			else ++cntB;
			++iter;
		}
		if (cntA > 2) {
			rA += cntA - 2;
		} else if (cntB > 2) {
			rB += cntB - 2;
		}
		i = iter-1;
		cntA = 1;
		cntB = 1;
	}

	return (rA - rB) >= 1;
}
