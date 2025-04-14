#include <Solution.h>
#include <iostream>

int Solution::countGoodTriplets(vector<int>& arr, int a, int b, int c) {
	int result = 0;
	for (int i = 0 ; i < arr.size() ; ++i) {
		for (int j = i + 1 ; j < arr.size() ; ++j) {
			for (int k = j + 1 ; k < arr.size() ; ++k) {
				if ((abs(arr[i] - arr[j]) > a) || (abs(arr[j]-arr[k]) > b) || (abs(arr[k] - arr[i]) > c)) continue;
				++result;
			}
		}
	}
	return result;
}
