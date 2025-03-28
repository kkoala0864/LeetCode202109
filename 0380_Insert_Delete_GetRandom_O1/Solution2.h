#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::swap;
using std::unordered_map;
using std::vector;

class RandomizedSet {
public:
	RandomizedSet() {
		srand(time(NULL));
	}

	bool insert(int val) {
		bool result = uMap.find(val) == uMap.end();
		if (result) {
			_vec.emplace_back(val);
			uMap[val] = _vec.size() - 1;
		}
		return result;
	}

	bool remove(int val) {
		bool result = uMap.find(val) != uMap.end();
		if (result) {
			int tail = _vec.back();
			uMap[tail] = uMap[val];
			swap(_vec[uMap[tail]], _vec.back());
			_vec.pop_back();
			uMap.erase(val);
		}
		return result;
	}

	int getRandom() {
		int rIdx = rand() % _vec.size();
		return _vec[rIdx];
	}

private:
	vector<int> _vec;
	unordered_map<int, int> uMap;
	virtual ~RandomizedSet() {
	}
	RandomizedSet &operator=(const RandomizedSet &source);
	RandomizedSet(const RandomizedSet &);
};
