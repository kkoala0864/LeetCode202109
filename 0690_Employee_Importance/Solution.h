#include <data_type.h>
#include <vector>

using std::vector;

class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
};

class Solution {
public:
	Solution() {
	}
	int getImportance(vector<Employee *> employees, int id);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
