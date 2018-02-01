#include "Eva.h"

BigInteger Eva::makeJ(std::string I) {
	std::string sha = sha1(I);
	J = BigUnsigned(BigUnsignedInABase(sha, 16));
	J %= n;
	return J;
}

BigInteger Eva::witness() {
	r = makeRandNumber(128);
	r %= n;

	//угадывание e
	BigInteger e = rand();
	e %= (v + 1);
	if (e == 0) e++;
	std::cout << "fake e = " << e << std::endl;

	BigInteger x = (powMod(r, v, n)*powMod(J, e, n)) % n;
	return x;
}

BigInteger Eva::response(BigInteger e) {
	BigInteger y = r % n;
	return y;
}
