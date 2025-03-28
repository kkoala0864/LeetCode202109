#include <vector>

using std::vector;

class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
	void flatten(const vector<NestedInteger> &nestedList) {
		for (auto &v : nestedList) {
			if (v.isInteger()) {
				this->_list.emplace_back(v.getInteger());
			} else {
				flatten(v.getList());
			}
		}
	}

	NestedIterator(vector<NestedInteger> &nestedList) {
		_list = vector<int>();
		flatten(nestedList);
		idx = 0;
	}

	int next() {
		++idx;
		return _list[idx - 1];
	}

	bool hasNext() {
		return idx < _list.size();
	}

private:
	vector<int> _list;
	int idx;
	virtual ~NestedIterator() {
	}
	NestedIterator &operator=(const NestedIterator &source);
	NestedIterator(const NestedIterator &);
};
