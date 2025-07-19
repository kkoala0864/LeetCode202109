#include <data_type.h>

class Skiplist {
public:
	Skiplist() {

	}

	bool search(int target) {
		return m.count(target);
	}

	void add(int num) {
		++m[num];
	}

	bool erase(int num) {
		if (m.count(num) == 0) return false;
		--m[num];
		if (m[num] == 0) m.erase(num);
		return true;
	}

private:
	map<int, int> m;
	virtual ~Skiplist() {}
	Skiplist &operator=(const Skiplist &source);
	Skiplist(const Skiplist &);
};
