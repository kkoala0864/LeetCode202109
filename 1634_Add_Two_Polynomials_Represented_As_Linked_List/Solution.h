#include <data_type.h>

struct PolyNode
{
	int coefficient, power;
	PolyNode *next;
	PolyNode()
	    : coefficient(0), power(0), next(nullptr){};
	PolyNode(int x, int y)
	    : coefficient(x), power(y), next(nullptr){};
	PolyNode(int x, int y, PolyNode *next)
	    : coefficient(x), power(y), next(next){};
};

class Solution {
public:
	Solution() {
	}
	PolyNode *addPoly(PolyNode *poly1, PolyNode *poly2);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
