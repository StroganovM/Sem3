#pragma once
#include <istream>
template<typename T>
class TVector {
	size_t _size;
	T* pMem;
	tupedef InIterator<T> iterator;
	tupedef InIterator<const T> iterator;
public:
	TVector(size_t size = 1) :_size(size) {
		if (size == 0 || size > MAX_VECTOR_SIZE) {
			throw std::lenght_error("Vector size too small or too big");
		}
		pMem = new T[size]();
	}

	TVector(T* data, size_t size) :_size(size) {
		assert(data != nullptr && "TVector constructor requires non-nullptr argument");
		pMem = new T[size];
		std::copy(data, data + size, pMem);
	}
	TVector(const TVector& v);
	TVector(TVector&& v) noexcept;
	~TVector();
	TVector& operator=(const TVector& v);
	TVector& operator=(TVector&& v) noexcept;
	size_t size() const noexcept;
	T& operator[](size_t ind);
	const T& operator[](size_t ind) const;
	T& at(size_t ind);
	const T& at(size_t ind) const;
	bool operator==(const TVector& v) const noexcept;
	bool operator!=(const Vector& v)const noexcept;
	TVector operator+(double val);
	TVector operator-(double val);
	TVector operator*(double val);
	TVector operator+(T val);
	TVector operator-(T val);
	TVector operator*(T val);
	TVector operator+(const Vector& v);
	TVector operator-(const Vector& v);
	T operator*(const Vector& v) noexcept(noexcept(T()));
	friend void swap(TVector& lhs, Vector& rhs) noexcept;
	friend std::istream& operator >> (std::istream& istr, TVector& v);
	friend std::ostream& operator << (std::ostream& ostr, const TVector& v);
};