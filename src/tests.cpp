/*
 * tests.cpp
 *
 *  Created on: Apr 16, 2009
 *      Author: jdw
 */

#include <iostream>
#include <math.h>

#include "lib/jdw_v2.h"
#include "lib/jdw_v3.h"
#include "lib/jdw_misc.h"
#include "lib/jdw_test.h"

using namespace std;

void test_v2() {
	V2d tmp = V2d();

	// Testing default values
	TEST_TRUE(tmp.x == 0);
	TEST_TRUE(tmp.y == 0);

	// Testing operators
	// =
	tmp = tmp;
	TEST_VAL(tmp, V2d());
	tmp.x = tmp.y = 0;
	TEST_VAL(tmp, V2d());
	TEST_VAL((tmp = V2d(2, 2)), V2d(2, 2));
	tmp.x = 0; tmp.y = 0;
	// ==
	TEST_TRUE(tmp == V2d());
	TEST_FALSE(tmp == V2d(1, 0));
	TEST_FALSE(tmp == V2d(0, 1));
	// !=
	TEST_TRUE(tmp != V2d(1, 0));
	TEST_TRUE(tmp != V2d(0, 1));
	// +
	TEST_VAL((tmp + V2d(23, 2)), V2d(23, 2));
	// +=
	tmp += V2d(23, 2);
	TEST_VAL(tmp, V2d(23, 2));
	tmp.x = 0; tmp.y = 0;
	// -
	TEST_VAL((tmp - V2d(23, 2)), V2d(-23, -2));
	// + -
	TEST_VAL((tmp + V2d(23, 2) - V2d(23, 2)), tmp);
	// - +
	TEST_VAL((tmp - V2d(23, 2) + V2d(23, 2)), tmp);
	// -=
	tmp -= V2d(27, 45);
	TEST_VAL(tmp, V2d(-27, -45));
	tmp.x = 0; tmp.y = 0;
	// *
	TEST_VAL((V2d(4, 2) * 5), V2d(20, 10));
	// *=
	tmp.x = 3; tmp.y = 7;
	tmp *= 5;
	TEST_VAL(tmp, V2d(15, 35));

	tmp.x = 2; tmp.y = 4;
	// Testing functions
	TEST_VAL(tmp.GetDP(V2d(4, 3)), 20);
	TEST_VAL(V2d(2.0, 4.0).GetUnit(), V2d(2.0 / sqrt(20.0), 4.0 / sqrt(20.0)));
	//TEST_VAL(tmp.GetXP(V2i(3, 7)), V2i(6, 28));
	TEST_VAL(tmp.GetLength(), sqrt(20));
	TEST_VAL(tmp.GetDist(V2d()), tmp.GetLength());
	TEST_VAL(tmp.GetDist(tmp), 0); // Testing against self
	TEST_VAL(tmp.GetDist(V2d(tmp.x, tmp.y)), 0); // Testing with same values
	TEST_VAL(tmp.GetUnit().GetLength(), 1);
}

void test_v3() {
	V3d tmp = V3d();

	// Testing default values
	TEST_TRUE(tmp.x == 0);
	TEST_TRUE(tmp.y == 0);
	TEST_TRUE(tmp.z == 0);

	// Testing operators
	// =
	tmp = tmp;
	TEST_VAL(tmp, V3d());
	tmp.x = tmp.y = tmp.z = 0;
	TEST_VAL(tmp, V3d());
	TEST_VAL((tmp = V3d(2, 2, 2)), V3d(2, 2, 2));
	tmp.x = tmp.y = tmp.z = 0;
	// ==
	TEST_TRUE(tmp == V3d());
	TEST_FALSE(tmp == V3d(1, 0, 0));
	TEST_FALSE(tmp == V3d(0, 1, 0));
	TEST_FALSE(tmp == V3d(0, 0, 1));
	// !=
	TEST_TRUE(tmp != V3d(1, 0, 0));
	TEST_TRUE(tmp != V3d(0, 1, 0));
	TEST_TRUE(tmp != V3d(0, 0, 1));
	// +
	TEST_VAL((tmp + V3d(3, 5, 7)), V3d(3, 5, 7));
	// +=
	tmp += V3d(3, 5, 7);
	TEST_VAL(tmp, V3d(3, 5, 7));
	tmp.x = tmp.y = tmp.z = 0;
	// -
	TEST_VAL((tmp - V3d(1337, 4711, 4242)), V3d(-1337, -4711, -4242));
	// + -
	TEST_VAL((tmp + V3d(23, 2, 7) - V3d(23, 2, 7)), tmp);
	// - +
	TEST_VAL((tmp - V3d(23, 2, 9) + V3d(23, 2, 9)), tmp);
	// -=
	tmp -= V3d(27, 45, 19);
	TEST_VAL(tmp, V3d(-27, -45, -19));
	tmp.x = tmp.y = tmp.z = 0;
	// *
	TEST_VAL((V3i(4, 2, 7) * 5), V3i(20, 10, 35));
	// *=
	tmp.x = 3;
	tmp.y = 5;
	tmp.z = 7;
	tmp *= 5;
	TEST_VAL(tmp, V3d(15, 25, 35));

	tmp.x = 3;
	tmp.y = 5;
	tmp.z = 7;
	// Testing functions
	TEST_VAL(tmp.GetDP(V3d(4, 3, 2)), 41);
	TEST_VAL(tmp.GetXP(V3d(12, 11, 10)), V3d(-27, 54, -27));
	TEST_VAL(tmp.GetLength(), sqrt(83));
	TEST_VAL(V3d(3.0, 5.0, 7.0).GetUnit(), V3d(3.0 / sqrt(83.0), 5.0 / sqrt(83.0), 7.0 / sqrt(83.0)));
	TEST_VAL(tmp.GetDist(V3d()), tmp.GetLength());
	TEST_VAL(tmp.GetDist(tmp), 0); // Testing against self
	TEST_VAL(tmp.GetDist(V3d(tmp.x, tmp.y, tmp.z)), 0); // Testing with same values
	TEST_VAL(tmp.GetUnit().GetLength(), tmp.GetUnit().GetLength());
	TEST_VAL(tmp.GetUnit().GetLength(), 1.0);
}

int main() {
	// All tests should go trough OK, and if so, should no output be given.

	// Testing 2d vectors
	test_v2();
	test_v3();
/*

	V3i* tmp_pV3i = new V3i();
	V3d* tmp_pV3d = new V3d();
	V3f* tmp_pV3f = new V3f();
*/
	exit(0);
}
