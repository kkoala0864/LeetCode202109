class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node* parent;
};

class Solution {
    public :
        Solution() {}
	Node* inorderSuccessor(Node* node);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

