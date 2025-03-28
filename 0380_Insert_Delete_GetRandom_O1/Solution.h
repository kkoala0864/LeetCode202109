#include <unordered_map>
#include <cstdlib>
#include <vector>
#include <ctime>

using std::swap;
using std::unordered_map;
using std::vector;

class RandomizedSet {
public:
	RandomizedSet() {
		srand(time(NULL));
	}

	bool insert(int val) {
		bool result = _map.find(val) == _map.end();
		if (result) {
			_vec.emplace_back(val);
			_map[val] = _vec.size() - 1;
		}
		return result;
	}

	bool remove(int val) {
		bool result = _map.find(val) != _map.end();
		if (result) {
			int tail = _vec.size() - 1;
			_map[_vec[tail]] = _map[val];
			swap(_vec[tail], _vec[_map[val]]);
			_vec.pop_back();
			_map.erase(val);
		}
		return result;
	}

	int getRandom() {
		int ran = rand() % _vec.size();
		return _vec[ran];
	}

private:
	unordered_map<int, int> _map;
	vector<int> _vec;
	virtual ~RandomizedSet() {
	}
	RandomizedSet &operator=(const RandomizedSet &source);
	RandomizedSet(const RandomizedSet &);
};
