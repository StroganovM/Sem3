#include "List.h"
template<typename T>
void TList<T> ::insert(TNode<T>* p, T data) {
	TNode* node = new TNode(data, p->next);
	p->next = node;
	count++;
	if (node->next == nulptr) {
		tail = data;
	}
}
template<typename T>
void TList<T> ::push_back(T data) {
	insert(tail, data);
}
template<typename T>
void TList<T> ::push_front(T data) {
	TNode* node = new TNode(data, head);
	head = node;
	count++;
	if (count == 1) {
		tail = head;
	}
}
template<typename T>
void TList<T> ::replace(TNode<T>* p, T data) {
	p->data = data;
}
