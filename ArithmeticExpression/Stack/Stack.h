template <class T>
class TStack {
	size_t size;
	T* data;
	size_t _top;
public:
	TStack(size_t _size) : size(_size), top(-1) {
		data = new T[size];
	}
	TStack(const TStack& st) : size(st.size), top(st.top) {
		std::copy(data, st.data);
	}
	~TStack() {
		delete[]data;
		data = nullptr;
	}
	T& top() {
		return data[_top];
	};
	void pop() {
		if (isEmpty()) {
			throw std::out_of_range("stack is empty");
		}
		else{
			top--;
		}
	}
	void push(T n) {
		if (isFull()) {
			throw std::out_of_range("stack is full");
		}

		else{
			data[++top] = n;
		}
			
	}
	void print() {
		for (int i = 0; i <= top; i++) {
			std::cout << i << " " << data[i] << std::endl;
		}
	}
	bool isFull() {
		return(size <= top + 1);
	}
	bool isEmpty() {
		return top == -1;
	}
};
