#include <iostream>
#include <string>
#include "BigIntegerLibrary.hh"
#include "GQ.h"
#include "Alice.h"
#include "Bob.h"
#include "Eva.h"
#include <ctime>

using namespace std;

void main() {
	srand(time(NULL));
	GQ T;
	Alice A;
	Bob B;
	Eva E;
	BigInteger v, n, J, s, x, e, y, Je;
	string name = "Natasha";
	int t; //кол-во раундов
	cout << "number of rounds: ";
	cin >> t;

	n = T.makeKeys(v);
	A.set(n, v);
	B.set(n, v);

	J = A.makeJ(name);


	s = T.accredit(J);
	cout << "sA = " << s << endl;

	A.setS(s);
	bool ver = true;
	for (int i = 0; i < t && ver == true; i++) { //раунды

		cout << endl;
		x = A.witness();
		cout << "A -> B: " << x << endl;
		e = B.challenge(x);
		cout << "A <- B: " << e << endl;
		y = A.response(e);
		cout << "A -> B: " << y << endl;

		if (!B.verify(y, J)) {
			cout << "false" << endl;
			ver = false;
		}
	}
	if (ver) cout << "true" << endl;
	cout << endl;

	for (int u = 0; u < 10; u++) {
		//ложная аутентификация
		E.set(n, v);
		Je = E.makeJ(name);
		s = T.accredit(Je);
		E.setS(s);
		ver = true;
		for (int i = 0; i < t && ver == true; i++) { //раунды

			cout << endl;
			x = E.witness();		cout << "A -> B: " << x << endl;
			e = B.challenge(x);		cout << "A <- B: " << e << endl;
			y = E.response(e);		cout << "A -> B: " << y << endl;

			if (!B.verify(y, Je)) {
				cout << "false" << endl;
				ver = false;
			}
		}
		if (ver) cout << "true" << endl;
	}

}