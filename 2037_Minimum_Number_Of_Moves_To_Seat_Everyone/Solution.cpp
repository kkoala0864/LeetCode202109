#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::minMovesToSeat(vector<int>& seats, vector<int>& students) {
	sort(seats.begin(), seats.end());
	sort(students.begin(), students.end());

	int result = 0;
	for (int i = 0 ; i < seats.size() ; ++i) {
		result += abs(seats[i] - students[i]);
	}
	return result;
}
