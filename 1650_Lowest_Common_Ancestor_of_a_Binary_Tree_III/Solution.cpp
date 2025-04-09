#include <Solution.h>
#include <iostream>
#include <unordered_set>

Node* Solution::lowestCommonAncestor(Node* p, Node * q) {
	auto pt = p, qt = q;

	// if p and q in same level, trivial
	// if p and q in different level
	//	p level : 3
	//	q level : 2
	//	total level = 3 + 2
	//	this way concatenate two lin with p to root and line with q to root to same line
	//	and no matter start which node, eventually would meeting at root which is line end;
	while (pt != qt) {
		pt = pt ? pt->parent : q;
		qt = qt ? qt->parent : p;
	}
	return pt;
}


