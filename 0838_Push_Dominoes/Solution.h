#include <data_type.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {
	}
	string pushDominoes(string dominoes);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
