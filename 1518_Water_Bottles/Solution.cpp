#include <Solution.h>
#include <iostream>

int Solution::numWaterBottles(int numBottles, int numExchange) {
	int result = numBottles;
	int empty = numBottles;

	while (empty >= numExchange) {
		int newFull = empty / numExchange;
		empty %= numExchange;
		result += newFull;
		empty += newFull;
	}
	return result;
}
