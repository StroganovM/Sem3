#include "bitfield.h"

size_t TBitField::GetMemIndex(size_t pos) const noexcept
{
	return memLen - pos / bitsInElem - 1;
}
elem_type TBitField::GetMemMask(size_t pos) const noexcept
{
	return 1 << (pos - GetMemIndex(pos) * bitsInElem);
}
TBitField::TBitField(size_t _BitLen)
{
	bitLen = _BitLen;
	bitsInElem = sizeof(elem_type) * 8;
	memLen = bitLen / bitsInElem;
	memLen += (bitLen % bitsInElem != 0);
	pMem = new elem_type[memLen];
	for (int i = 0; i < memLen; i++) { pMem[i] = 0; }
	shiftSize = 0;
}
TBitField::TBitField(const TBitField& bf)
{
	bitLen = bf.bitLen;
	bitsInElem = bf.bitsInElem;
	memLen = bf.memLen;
	pMem = new elem_type[memLen];
	for (int i = 0; i < memLen; i++) { pMem[i] = bf.pMem[i]; }
	shiftSize = bf.shiftSize;
}
TBitField::TBitField(TBitField&& bf) noexcept :bitLen(0), memLen(0),
shiftSize(0), bitsInElem(0), pMem(nullptr)
{
	bitLen = bf.bitLen;
	bitsInElem = bf.bitsInElem;
	memLen = bf.memLen;
	pMem = bf.pMem;
	shiftSize = bf.shiftSize;
	bf.pMem = nullptr;
	bf.bitLen = 0;
	bf.bitsInElem = 0;
	bf.memLen = 0;
	bf.shiftSize = 0;
}
TBitField::~TBitField()
{
	delete[] pMem;
}
TBitField& TBitField::operator=(const TBitField& bf)
{
	if (this == &bf) { return *this; }
	bitLen = bf.bitLen;
	bitsInElem = bf.bitsInElem;
	memLen = bf.memLen;
	pMem = new elem_type[memLen];
	for (int i = 0; i < memLen; i++) { pMem[i] = bf.pMem[i]; }
	shiftSize = bf.shiftSize;
	return *this;
}
TBitField& TBitField::operator=(TBitField&& bf) noexcept
{
	if (this == &bf) { return *this; }
	delete[] pMem;
	bitLen = bf.bitLen;
	bitsInElem = bf.bitsInElem;
	memLen = bf.memLen;
	pMem = bf.pMem;
	shiftSize = bf.shiftSize;
	bf.pMem = nullptr;
	bf.bitLen = 0;
	bf.bitsInElem = 0;
	bf.memLen = 0;
	bf.shiftSize = 0;
	return *this;
}
bool TBitField::operator==(const TBitField& bf) const noexcept
{
	if ((bitLen != bf.bitLen) || (memLen != bf.memLen) || (shiftSize != bf.shiftSize)) {
		return false;
	}
	for (int i = 0; i < bitLen; i++) {
		if (test(i) != bf.test(i)) { return false; }
	}
	return true;
}
bool TBitField::operator!=(const TBitField& bf) const noexcept
{
	return not(*this == bf);
}
bool TBitField::test(size_t i) const
{
	if ((i < bitLen) && (i >= 0)) {
		return pMem[GetMemIndex(i)] & GetMemMask(i);
	}
	else { throw std::logic_error("i out of universe"); }
}
void TBitField::set(size_t i)
{
	if ((i < bitLen) && (i >= 0)) {
		pMem[GetMemIndex(i)] = pMem[GetMemIndex(i)] | GetMemMask(i);
	}
	else { throw std::logic_error("i out of universe"); }
}
void TBitField::reset(size_t i)
{
	if ((i < bitLen) && (i >= 0)) {
		pMem[GetMemIndex(i)] = pMem[GetMemIndex(i)] & ~(GetMemMask(i));
	}
	else { throw std::logic_error("i out of universe"); }
}
TBitField TBitField::operator|(const TBitField& bf) {
	size_t minBitLen = std::min(bitLen, bf.bitLen);
	size_t minMemLen = std::min(memLen, bf.memLen);

	TBitField res(std::max(bitLen, bf.bitLen));

	for (size_t i = 0; i < minMemLen; ++i) {
		res.pMem[i] = pMem[i] | bf.pMem[i];
	}

	if (bitLen < bf.bitLen) {
		for (size_t i = minMemLen; i < res.memLen; ++i) {
			res.pMem[i] = bf.pMem[i];
		}
	}
	if (bitLen > bf.bitLen) {
		for (size_t i = minMemLen; i < res.memLen; ++i) {
			res.pMem[i] = pMem[i];
		}
	}
	

	return res;
}

TBitField TBitField::operator&(const TBitField& bf) {
	size_t minBitLen = std::min(bitLen, bf.bitLen);
	size_t minMemLen = std::min(memLen, bf.memLen);

	TBitField res(std::max(bitLen, bf.bitLen));

	for (size_t i = 0; i < minMemLen; ++i) {
		res.pMem[i] = pMem[i] & bf.pMem[i];
	}

	if (bitLen > bf.bitLen) {
		for (size_t i = minMemLen; i < res.memLen; ++i) {
			res.pMem[i] = 0;
		}
	}

	return res;
}
TBitField TBitField::operator~(void)
{
	TBitField tmp(*this);
	for (int i = 0; i < memLen; i++) {
		tmp.pMem[i] = ~pMem[i];
	}
	return tmp;
}
size_t TBitField::size() const noexcept
{
	return bitLen;
}
std::string TBitField::to_string()
{
	std::string tmp;
	for (int i = 0; i < bitLen; i++) {
		if (test(i) == 1) { tmp = tmp + "1"; }
		else { tmp = tmp + "0"; }
	}
	return tmp;
}
void swap(TBitField& lhs, TBitField& rhs) noexcept
{
	std::swap(lhs, rhs);
}
std::ostream& operator<<(std::ostream& ostr, const TBitField& bf)
{
	for (int i = 0; i < bf.bitLen; i++) {
		ostr << "[" << i << "] = " << bf.test(i)<<" ";
	}
	ostr << std::endl;
	return ostr;
}
