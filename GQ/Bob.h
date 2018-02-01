#pragma once
#include "DSA.h"

class Bob {
private:
	BigInteger e, x, v, n;
public:
	Bob() {};
	~Bob() {};
	//получение открытых v, n
	void set(BigInteger n, BigInteger v) { this->n = n; this->v = v; }

	//получает x, генерирует случ. e
	BigInteger challenge(BigInteger x);

	//проверка доказательства
	bool verify(BigInteger y, BigInteger J);
};