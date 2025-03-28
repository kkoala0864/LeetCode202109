#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

vector<int> Solution::asteroidCollision(vector<int> &asteroids) {
	vector<int> st;
	for (int i = 0; i < asteroids.size(); ++i) {
		if (asteroids[i] < 0) {
			while (!st.empty() && st.back() > 0) {
				int top = st.back();
				if (top <= -asteroids[i]) {
					st.pop_back();
				}
				if (top >= -asteroids[i]) {
					asteroids[i] = 0;
					break;
				}
			}
		}
		if (asteroids[i] != 0)
			st.emplace_back(asteroids[i]);
	}
	return st;
}
