#include <Solution.h>

// x₁y₂ + x₂y₃ + x₃y₁ - x₁y₃ - x₂y₁ - x₃y₂
double getArea(const vector<int>& x, const vector<int>& y, const vector<int>& z) {
	int v = x[0] * y[1] + y[0] * z[1] + z[0] * x[1] - x[0] * z[1] - y[0] * x[1] - z[0] * y[1];
	return abs(v) * 0.5;
}

double Solution::largestTriangleArea(vector<vector<int>>& points) {
	double result = 0;
	for (int i = 2 ; i < points.size() ; ++i) {
		for (int j = 1 ; j < i ; ++j) {
			for (int k = 0 ; k < j ; ++k) {
				result = max(result, getArea(points[i], points[j], points[k]));
			}
		}
	}
	return result;

}
