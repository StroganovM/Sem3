#include <iostream>
#include<stdexcept>
#ifndef INCLUDE_QUEUE_H_
#define INCLUDE_QUEUE_H_
template <class T>
class TQueue;
template<class T>
std::ostream& operator << (std::ostream& out, const TQueue<T>& q) {
	size_t i = q._front;

	while (i != q._rear) {
		out << "| " << q.data[i] << " |\n";
		i = (i + 1) % q._size;
	}

	out << "|---|\n";

	return out;
}
template <class T>
class TQueue {
	size_t _size;
	size_t _front;
	size_t _rear;
	T* data;

public:
	TQueue(size_t sz) : _size(sz), _front(0), _rear(0) {
		if (sz > ULLONG_MAX)
			throw std::invalid_argument("neprvilno");
		data = new T[sz];
	}

	TQueue(const TQueue& q) : _size(q._size), _front(q._front), _rear(q._rear) {
		std::copy(data, q.data);
	}

	~TQueue() {
		delete[] data;
		data = nullptr;
	}

	bool isFull() const {
		return _rear == _size;
	}

	bool isEmpty() const {
		return _front == _rear;
	}

	void push(const T& value) {
		if (isFull()) {
			throw std::out_of_range("queue is full");
		}

		data[_rear] = value;
		_rear++;
	}

	void pop() {
		if (isEmpty()) {
			throw std::out_of_range("queue is empty");
		}
		for (size_t i = _front; i < _rear; i++) {
			data[i] = data[i + 1];
		}
		_rear--;
	}

	T& front() {
		if (isEmpty()) {
			throw std::out_of_range("queue is empty");
		}
		return data[_front];
	}

	friend std::ostream& operator << (std::ostream& out, const TQueue<T>& q);
};

#endif //INCLUDE_QUEUE_H_