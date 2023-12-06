#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_
template< class T>
class TNode {
	T data;
	TNode* next;
public:
	TNode(const TNode& node);
	TNode(Tdata, TNode* next = nulptr);
	std::stringtoString();
	bool operator==(const TNode const noexcept;
	TNode& operator=(const TNode& s);
	friend ostream& operator<<(ostream& ostr, const TNode& v);

};
template<class T>
class TList {
	friend class TNode;
	TNode* head;
	TNode* tail;
	int count;
public:
	TList();
	TList(T* massData);
	void clear();
	bool isEntry();
	void push_back(T data);
	void push_front(T data);
	void insert(TNode* p, T data);
	void replace(TNode* p, T data);
	~TList();
};
#endif // INCLUDE_LIST_H_