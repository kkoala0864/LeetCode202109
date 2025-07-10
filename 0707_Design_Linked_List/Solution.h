#include <data_type.h>

class Node {
	public :
		Node() {}
		Node(int val) : val(val) {};
		int val;
		Node* prev;
		Node* next;
};

class MyLinkedList {
public:
	MyLinkedList() {
		root = nullptr;
		size = 0;
	}

	int get(int index) {
		if (index > (size - 1)) return -1;
		Node* iter = root;
		while (index-- > 0) {
			iter = iter->next;
		}
		return iter->val;
	}

	void addAtHead(int val) {
		if (!root) {
			root = new Node(val);
			root->next = root;
			root->prev = root;
		} else {
			Node* prev = root->prev;
			Node* node = new Node(val);
			prev->next = node;
			node->prev = prev;
			node->next = root;
			root->prev = node;
			root = node;
		}
		++size;
	}

	void addAtTail(int val) {
		if (!root) {
			root = new Node(val);
			root->next = root;
			root->prev = root;
		} else {
			Node* prev = root->prev;
			Node* node = new Node(val);
			prev->next = node;
			node->prev = prev;
			node->next = root;
			root->prev = node;
		}
		++size;
	}

	void addAtIndex(int index, int val) {
		int cnt = index;
		if (cnt > size) return;
		if (cnt == size) {
			addAtTail(val);
		} else {
			Node* prev = root->prev;
			Node* iter = root;
			while (cnt-- > 0) {
				prev = iter;
				iter = iter->next;
			}
			Node* node = new Node(val);
			node->prev = prev;
			node->next = iter;
			iter->prev = node;
			prev->next = node;
			if (index == 0) root = root->prev;
			++size;
		}
	}

	void deleteAtIndex(int index) {
		if (index > (size - 1)) return;
		int cnt = index;
		if (size == 1) {
			root = nullptr;
			--size;
			return;
		}
		Node* iter = root;
		while (cnt-- > 0) {
			iter = iter->next;
		}
		Node* prev = iter->prev;
		Node* next = iter->next;
		prev->next = next;
		next->prev = prev;
		if (index == 0) root = prev->next;
		--size;
	};

private:
	Node* root;
	int size;
	virtual ~MyLinkedList() {
	}
	MyLinkedList &operator=(const MyLinkedList &source);
	MyLinkedList(const MyLinkedList &);
};
