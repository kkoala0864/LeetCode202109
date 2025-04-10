#include <data_type.h>

using namespace std;

class Node {
	public:
		int val;
		Node* next;

		Node() {}

		Node(int _val) {
			val = _val;
			next = nullptr;
		}

		Node(int _val, Node* _next) {
			val = _val;
			next = _next;
		}
};

class Solution {
public:
	Solution() {
	}
	Node* insert(Node* head, int insertVal);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
