#include "Alice.h"

BigInteger Alice::makeJ(std::string I) {
	std::string sha = sha1(I);
	J = BigUnsigned(BigUnsignedInABase(sha, 16));
	J %= n;
	return J;
}

BigInteger Alice::witness() {
	r = makeRandNumber(128);
	r %= n;

	BigInteger x = powMod(r, v, n);

	return x;
}

BigInteger Alice::response(BigInteger e) {
	BigInteger y = (r*powMod(sA, e, n)) % n;
	return y;
}
