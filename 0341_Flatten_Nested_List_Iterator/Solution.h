/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <vector>

using std::vector;

class NestedIterator {
public:
	void flatten(vector<NestedInteger> &list) {
		for (const auto &iter : list) {
			if (iter.isInteger()) {
				_vec.emplace_back(iter.getInteger());
			} else {
				flatten(iter.getList());
			}
		}
	}

	NestedIterator(vector<NestedInteger> &nestedList) {
		_vec = vector<int>();
		flatten(nestedList);
		idx = 0;
	}

	int next() {
		if (idx < _vec.size())
			return _vec[idx++];
		return -1;
	}

	bool hasNext() {
		return idx < _vec.size();
	}

private:
	vector<int> _vec;
	int idx;
	virtual ~NestedIterator() {
	}
	NestedIterator &operator=(const NestedIterator &source);
	NestedIterator(const NestedIterator &);
};
