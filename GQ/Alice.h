#pragma once
#include "DSA.h"
#include "sha1.h"
#include <string>

class Alice {
private:
	BigInteger J, v, n, sA, r;
public:
	Alice() {};
	~Alice() {};
	//получение открытых v, n
	void set(BigInteger n, BigInteger v) { this->n = n; this->v = v; }

	//рассчет J из строки
	BigInteger makeJ(std::string I);

	//получение секрета
	void setS(BigInteger s) { sA = s; }

	//вручение и свидетельство
	BigInteger witness();

	//вычисление отзыва y
	BigInteger response(BigInteger e);
};