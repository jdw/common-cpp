/*
 * jdw_tuple.h
 *
 *  Created on: Apr 19, 2009
 *      Author: jdw
 */

#ifndef JDW_TUPLE
#define JDW_TUPLE

template <class T, class U>
class JDW_Tuple {
	JDW_Tuple(T* in_pT, U* in_pU) {
		TEST_PTR(in_pT);
		TEST_PTR(in_pU);

		pT = in_pT;
		pU = in_pU;
	}

	~JDW_Tuple() {
		delete pT;
		delete pU;
	}

	T* pV;
	U* pW;
};

#endif
