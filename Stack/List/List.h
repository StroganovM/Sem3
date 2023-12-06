#include <iostream>
#include <stdexcept>
#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_
template <class T>
class TNode;
template <class T>
class TList;
template< class T>
class TNode {
	friend class TList<T>;
	T _data;
	TNode* next;
public:
	TNode(const TNode& p) :_data(data), next(p) {}
	TNode(T data, TNode* next = nullptr):_data(data), next(next) {}
	//std::StringtoString();
	bool operator==(const TNode node) const noexcept {
		return _data == node._data && next == node.next;
	}
	TNode& operator=(const TNode& node) {
		_data = node._data;
		next = node.next;
		return *this;
	}
	
	~TNode() {
		next = nullptr;
	}
	//friend ostream& operator<<(ostream& ostr, const TNode& v);

};
template<class T>
class TList {
	friend class TNode<T>;
	TNode<T>* head;
	TNode<T>* tail;
	int count;
public:
	TList() : head(nullptr), tail(nullptr), count(0) {}
	TList(T* data, int mass_size) {
		if (mass_size < 1) { throw std::logic_error("Mass is empty"); }
		count = mass_size;
		head = new TNode<T>(data[0]);
		TNode<T>* p = head;
		for (size_t i = 1; i < mass_size; i++) {
			p->next = new TNode<T>(data[i]);
			p = p->next;
		}
		tail = p;
	}

	void Delete(TNode<T>* p) {
		if (p == nullptr) { return; }
		if (p == head) { head = p->next; }
		else
		{
			TNode<T>* tmp = head;
			while (tmp->next != p && tmp->next != nullptr) {
				tmp = tmp->next;
			}
			if (tmp->next == nullptr) { throw std::logic_error("node is missing"); }
			tmp->next = p->next;
			if (tmp->_next == nullptr) { tail = tmp; }
		}
		delete p;
		count--;
		if (head == nullptr) { tail = nullptr; }
	}
	bool isEmpty() {
		return(count == 0);
	}
	void push_back_(T data) {
		insert(tail, data);
	}
	
	void push_front_(T data){
		TNode<T>* node = new TNode<T>(data, head);
		head = node;
		count++;
		if (count == 1) {
			tail = head;
		}
	}
	void insert(TNode<T>* p,T data){
		TNode<T>* node = new TNode<T>(data, p->next);
		p->next = node;
		count++;
		if (node->next == nullptr) {
			*tail = data;
		}
	}
	void replace(TNode<T>* p, T data){
		p->_data = data;
	}
	void pop_back() { clear(tail); }
	void pop_front() { clear(head); }
	T front() { return head->data(); }
	T back() { return tail->data(); }
	TNode<T>* front_node() { return head; }
	~TList() {
		TNode<T>* currentNode = head;
		while (currentNode != nullptr) {
			TNode<T>* nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
		
	}
};
#endif // INCLUDE_LIST_H_
