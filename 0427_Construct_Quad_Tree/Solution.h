#include <data_type.h>

class Node {
	public:
		bool val;
		bool isLeaf;
		Node* topLeft;
		Node* topRight;
		Node* bottomLeft;
		Node* bottomRight;

		Node() {
			val = false;
			isLeaf = false;
			topLeft = NULL;
			topRight = NULL;
			bottomLeft = NULL;
			bottomRight = NULL;
		}

		Node(bool _val, bool _isLeaf) {
			val = _val;
			isLeaf = _isLeaf;
			topLeft = NULL;
			topRight = NULL;
			bottomLeft = NULL;
			bottomRight = NULL;
		}

		Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
			val = _val;
			isLeaf = _isLeaf;
			topLeft = _topLeft;
			topRight = _topRight;
			bottomLeft = _bottomLeft;
			bottomRight = _bottomRight;
		}
};

using namespace std;

class Solution {
public:
	Solution() {
	}
	Node* construct(vector<vector<int>>& grid);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
