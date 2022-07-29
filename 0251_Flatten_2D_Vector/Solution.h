#include <vector>

using std::vector;

class Vector2D {
    public :
	Vector2D(vector<vector<int>>& vec) {
		_v = vec;
		rit = _v.begin();
		if (rit != _v.end()) {
			cit = rit->begin();
			while (rit != _v.end() && cit == rit->end()) {
				++rit;
				if (rit != _v.end()) cit = rit->begin();
			}
		}
	}

	int next() {
		int result = *cit;
		++cit;
		while (rit != _v.end() && cit == rit->end()) {
			++rit;
			if (rit != _v.end()) cit = rit->begin();
		}
		return result;
	}

	bool hasNext() {
		return rit != _v.end();
	}
    private :
	vector<vector<int>> _v;
	vector<int>::iterator cit;
	vector<vector<int>>::iterator rit;
        virtual ~Vector2D() {}
        Vector2D& operator=(const Vector2D& source);
        Vector2D(const Vector2D&);
};

