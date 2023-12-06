#include"List.h"
template<class T>
class StackOnList {
	TList<T> data;
public:
	StackOnList() :data() {}
	StackOnList(const StackOnList& st) :data(st.data) {}
	StackOnList(T* data, int mass_size) : data(data, mass_size) {}
	~StackOnList() {}

	bool isEmpty() { return data.empty(); }
	T top() {
		if (data.isEmpty()) { throw std::logic_error("stack is empty"); }
		return data.back();
	}
	void pop() {
		if (data.empty()) { return; }
		data.pop_back();
	}
	void push(const T& elem) { data.push_back(elem); }
	size_t size() { return data.size(); }
};