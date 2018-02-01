#include "Bob.h"
#include <iostream>

BigInteger Bob::challenge(BigInteger x)
{
	this->x = x;

	e = rand();
	e %= (v + 1);
	if (e == 0) e++;

	return e;
}

bool Bob::verify(BigInteger y, BigInteger J) {
	BigInteger z = (powMod(J, e, n)*powMod(y, v, n)) % n;
	std::cout << "z = " << z << std::endl;

	if (z == 0)
		return false;
	if (z == x)
		return true;
	return false;
}
