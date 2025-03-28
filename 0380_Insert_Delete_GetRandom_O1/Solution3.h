#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using std::swap;
using std::unordered_map;
using std::vector;

class RandomizedSet {
public:
	RandomizedSet() {
		srand(time(NULL));
	}

	bool insert(int val) {
		if (idxMap.find(val) != idxMap.end())
			return false;
		_vec.emplace_back(val);
		idxMap[val] = _vec.size() - 1;
		return true;
	}

	bool remove(int val) {
		if (idxMap.find(val) == idxMap.end())
			return false;
		int removeIdx = idxMap[val];
		idxMap[_vec.back()] = removeIdx;
		swap(_vec[removeIdx], _vec[_vec.size() - 1]);
		_vec.pop_back();
		idxMap.erase(val);
		return true;
	}

	int getRandom() {
		int idx = rand() % _vec.size();
		return _vec[idx];
	}

private:
	vector<int> _vec;
	unordered_map<int, int> idxMap;
	virtual ~RandomizedSet() {
	}
	RandomizedSet &operator=(const RandomizedSet &source);
	RandomizedSet(const RandomizedSet &);
};
