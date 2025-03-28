#include <Solution.h>
#include <iostream>

PolyNode *Solution::addPoly(PolyNode *poly1, PolyNode *poly2) {
	auto i1 = poly1;
	auto i2 = poly2;

	PolyNode *iter = new PolyNode();
	PolyNode *result = iter;

	while (i1 && i2) {
		if (i1->power == i2->power) {
			if (i1->coefficient + i2->coefficient != 0) {
				iter->next = new PolyNode();
				iter = iter->next;
				iter->power = i1->power;
				iter->coefficient = i1->coefficient + i2->coefficient;
			}
			i1 = i1->next;
			i2 = i2->next;
		} else {
			if (i1->power > i2->power) {
				iter->next = i1;
				i1 = i1->next;
			} else {
				iter->next = i2;
				i2 = i2->next;
			}
			iter = iter->next;
		}
	}
	iter->next = i1 ? i1 : i2;
	return result->next;
}
