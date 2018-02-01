#include "GQ.h"

BigInteger GQ::makeKeys(BigInteger & v)
{
	p = makeNumber(128);
	do {
		p++;
	} while (!MillerRabin(p, 10));

	q = makeNumber(128);
	do {
		q++;
	} while (!MillerRabin(q, 10));

	n = p*q;
	phi = (p - 1)*(q - 1);

	//экспоненты
	v = 3;
	BigInteger d, x, y;
	Euclid(v, phi, d, x, y);
	while (d != 1) {
		v++;
		Euclid(v, phi, d, x, y);
	}
	this->v = v;

	s = inverse(v, phi);
		std::cout << "p = " << p << std::endl << "q = " << q << std::endl
			<< "n = " << n << std::endl << "v = " << v << std::endl << std::endl;

	return n;
}

BigInteger GQ::accredit(const BigInteger& J) {
	BigInteger base, sA;
	base = inverse(J, n);
	sA = powMod(base, s, n);
	return sA;
}
