/*
 * tests.cpp
 *
 *  Created on: Apr 16, 2009
 *      Author: jdw
 */

#include <iostream>
#include <math.h>

#include "lib/jdw_vector2d.h"
#include "lib/jdw_vector3d.h"
#include "lib/jdw_misc.h"
#include "lib/jdw_test.h"
#include "lib/jdw_vertex.h"
#include "lib/jdw_polygon.h"
#include "lib/jdw_camera.h"
#include "lib/jdw_cube.h"
#include "lib/jdw_improvedperlinnoise.h"

using namespace std;

void test_v2() {
	dV2 tmp = dV2();
	// Testing default values
	TEST_TRUE(tmp.x == 0);
	TEST_TRUE(tmp.y == 0);

	// Testing operators
	// =
	tmp = tmp;
	TEST_VAL(tmp, dV2());
	tmp.x = tmp.y = 0;
	TEST_VAL(tmp, dV2());
	TEST_VAL((tmp = dV2(2, 2)), dV2(2, 2));
	tmp.x = 0; tmp.y = 0;
	// ==
	TEST_TRUE(tmp == dV2());
	TEST_FALSE(tmp == dV2(1, 0));
	TEST_FALSE(tmp == dV2(0, 1));
	// !=
	TEST_TRUE(tmp != dV2(1, 0));
	TEST_TRUE(tmp != dV2(0, 1));
	// +
	TEST_VAL((tmp + dV2(23, 2)), dV2(23, 2));
	// +=
	tmp += dV2(23, 2);
	TEST_VAL(tmp, dV2(23, 2));
	tmp.x = 0; tmp.y = 0;
	// -
	TEST_VAL((tmp - dV2(23, 2)), dV2(-23, -2));
	// + -
	TEST_VAL((tmp + dV2(23, 2) - dV2(23, 2)), tmp);
	// - +
	TEST_VAL((tmp - dV2(23, 2) + dV2(23, 2)), tmp);
	// -=
	tmp -= dV2(27, 45);
	TEST_VAL(tmp, dV2(-27, -45));
	tmp.x = 0; tmp.y = 0;
	// *
	TEST_VAL((dV2(4, 2) * 5), dV2(20, 10));
	// *=
	tmp.x = 3; tmp.y = 7;
	tmp *= 5;
	TEST_VAL(tmp, dV2(15, 35));

	tmp.x = 2; tmp.y = 4;
	// Testing functions
	TEST_VAL(tmp.GetDP(dV2(4, 3)), 20);
	TEST_VAL(dV2(2.0, 4.0).GetUnit(), dV2(2.0 / sqrt(20.0), 4.0 / sqrt(20.0)));
	//TEST_VAL(tmp.GetXP(V2i(3, 7)), V2i(6, 28));
	TEST_VAL(tmp.GetLength(), sqrt(20));
	TEST_VAL(tmp.GetDist(dV2()), tmp.GetLength());
	TEST_VAL(tmp.GetDist(tmp), 0); // Testing against self
	TEST_VAL(tmp.GetDist(dV2(tmp.x, tmp.y)), 0); // Testing with same values
	TEST_VAL(tmp.GetUnit().GetLength(), 1);
}

void test_v3() {
	dV3 tmp = dV3();

	// Testing default values
	TEST_TRUE(tmp.x == 0);
	TEST_TRUE(tmp.y == 0);
	TEST_TRUE(tmp.z == 0);

	// Testing operators
	// =
	tmp = tmp;
	TEST_VAL(tmp, dV3());
	tmp.x = tmp.y = tmp.z = 0;
	TEST_VAL(tmp, dV3());
	TEST_VAL((tmp = dV3(2, 2, 2)), dV3(2, 2, 2));
	tmp.x = tmp.y = tmp.z = 0;
	// ==
	TEST_TRUE(tmp == dV3());
	TEST_FALSE(tmp == dV3(1, 0, 0));
	TEST_FALSE(tmp == dV3(0, 1, 0));
	TEST_FALSE(tmp == dV3(0, 0, 1));
	// !=
	TEST_TRUE(tmp != dV3(1, 0, 0));
	TEST_TRUE(tmp != dV3(0, 1, 0));
	TEST_TRUE(tmp != dV3(0, 0, 1));
	// +
	TEST_VAL((tmp + dV3(3, 5, 7)), dV3(3, 5, 7));
	// +=
	tmp += dV3(3, 5, 7);
	TEST_VAL(tmp, dV3(3, 5, 7));
	tmp.x = tmp.y = tmp.z = 0;
	// -
	TEST_VAL((tmp - dV3(1337, 4711, 4242)), dV3(-1337, -4711, -4242));
	// + -
	TEST_VAL((tmp + dV3(23, 2, 7) - dV3(23, 2, 7)), tmp);
	// - +
	TEST_VAL((tmp - dV3(23, 2, 9) + dV3(23, 2, 9)), tmp);
	// -=
	tmp -= dV3(27, 45, 19);
	TEST_VAL(tmp, dV3(-27, -45, -19));
	tmp.x = tmp.y = tmp.z = 0;
	// *
	TEST_VAL((iV3(4, 2, 7) * 5), iV3(20, 10, 35));
	// *=
	tmp.x = 3;
	tmp.y = 5;
	tmp.z = 7;
	tmp *= 5;
	TEST_VAL(tmp, dV3(15, 25, 35));

	tmp.x = 3;
	tmp.y = 5;
	tmp.z = 7;
	// Testing functions
	TEST_VAL(tmp.GetDP(dV3(4, 3, 2)), 41);
	TEST_VAL(tmp.GetXP(dV3(12, 11, 10)), dV3(-27, 54, -27));
	TEST_VAL(tmp.GetLength(), sqrt(83));
	TEST_VAL(dV3(3.0, 5.0, 7.0).GetUnit(), dV3(3.0 / sqrt(83.0), 5.0 / sqrt(83.0), 7.0 / sqrt(83.0)));
	TEST_VAL(tmp.GetDist(dV3()), tmp.GetLength());
	TEST_VAL(tmp.GetDist(tmp), 0); // Testing against self
	TEST_VAL(tmp.GetDist(dV3(tmp.x, tmp.y, tmp.z)), 0); // Testing with same values
	TEST_VAL(tmp.GetUnit().GetLength(), tmp.GetUnit().GetLength());
	TEST_VAL(tmp.GetUnit().GetLength(), 1.0);
}

int main() {
	// All tests should go trough OK, and if so, no output be given.

	test_v2();
	test_v3();

	exit(0);
}
