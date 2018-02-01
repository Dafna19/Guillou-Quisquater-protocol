#pragma once
#include "DSA.h"
#include "sha1.h"

class GQ {
private:
	BigInteger p, q, s, v, phi, n;//для T
public:
	GQ() {};
	~GQ() {};
	//возвращает n = pq, вычисляет простые p, q, v
	BigInteger makeKeys(BigInteger &v);

	//выдает аккредитацию
	BigInteger accredit(const BigInteger& J);
};