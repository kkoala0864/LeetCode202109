#include <Solution.h>

vector<double> Solution::getCollisionTimes(vector<vector<int>>& cars) {
	int size = cars.size();
	vector<double> result(size, -1);
	stack<int> st;

	for (int i = size - 1 ; i >= 0 ; --i) {

		while (!st.empty()) {
			int lidx = st.top();

			if (cars[lidx][1] >= cars[i][1]) {
				st.pop();
				continue;
			}

			double p = cars[lidx][0] - cars[i][0];
			double s = cars[i][1] - cars[lidx][1];
			double t = p / s;

			if (result[lidx] != -1 && result[lidx] <= t) {
				st.pop();
				continue;
			}
			result[i] = t;
			break;
		}
		st.emplace(i);
	}
	return result;
}

