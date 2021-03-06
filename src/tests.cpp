/*
 * tests.cpp
 *
 *  Created on: Apr 16, 2009
 *      Author: jdw
 */

#include <iostream>
#include <fstream>
#include <math.h>

// Tests won't run without 'DEBUG'
#define DEBUG 1

#include "lib/jdw_types.h"
#include "lib/jdw_vector2d.h"
#include "lib/jdw_vector3d.h"
#include "lib/jdw_misc.h"
#include "lib/jdw_test.h"
#include "lib/jdw_vertex.h"
#include "lib/jdw_polygon.h"
#include "lib/jdw_camera.h"
#include "lib/jdw_cube.h"
#include "lib/jdw_improvedperlinnoise.h"
#include "lib/jdw_list.h"
#include "lib/jdw_pixel.h"
#include "lib/jdw_image.h";

using namespace std;

void TestVector2d() {
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

void TestVector3d() {
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

void TestList() {
	int val = 1;
	iList* tmp = new iList(new int(val));
	int sum = val;
	val++;
	TEST_PTR(tmp);
	TEST_PTR(tmp->pObj);

	for (; val < 6; val++) {
		sum += val;
		tmp->Add(new int(val));
	}

	TEST_VAL(tmp->Size(), 5);

	iList* it = tmp;
	int it_sum = 0;
	while (it != NULL) {
		if (it->pObj != NULL) it_sum += *it->pObj;
		it = it->pNext;
	}

	tmp->DelAllObj();
	delete tmp;

	TEST_VAL(it_sum, sum);
}

void TestPixel() {
	JDW_Pixel tmp;
	tmp.integer = 0;

	TEST_VAL(tmp.a, 0);
	TEST_VAL(tmp.r, 0);
	TEST_VAL(tmp.g, 0);
	TEST_VAL(tmp.b, 0);
	TEST_VAL(tmp.integer, 0);

	tmp.a = 16;
	tmp.r = 32;
	tmp.g = 64;
	tmp.b = 128;

	TEST_VAL(tmp.a, 16);
	TEST_VAL(tmp.r, 32);
	TEST_VAL(tmp.g, 64);
	TEST_VAL(tmp.b, 128);
	TEST_TRUE(tmp.integer != 0);
}

void TestIO() {
	JDW_Image<JDW_Pixel, JDW_Pixel>* tmp_pImg1 = new JDW_Image<JDW_Pixel, JDW_Pixel>(iV2(2, 3));
	tmp_pImg1->PutPixel(iV2(0,0), JDW_Pixel(0, 0, 0));
	tmp_pImg1->PutPixel(iV2(1,0), JDW_Pixel(255, 0, 0));
	tmp_pImg1->PutPixel(iV2(0,1), JDW_Pixel(0, 255, 0));
	tmp_pImg1->PutPixel(iV2(1,1), JDW_Pixel(0, 0, 255));
	tmp_pImg1->PutPixel(iV2(0,2), JDW_Pixel(255, 0, 255));
	tmp_pImg1->PutPixel(iV2(1,2), JDW_Pixel(255, 255, 255));
	tmp_pImg1->SetTrans(JDW_Pixel(255, 255, 255));

	ofstream fout("test.data", ios::binary);
	fout.write((char *)(&tmp_pImg1->GetSize()), sizeof(tmp_pImg1->GetSize()));
	fout.write((char *)(tmp_pImg1), sizeof(*tmp_pImg1));
	fout.close();

	ifstream fin("test.data", ios::binary);

	iV2 tmp_size = iV2();
	fin.read((char *)(&tmp_size), sizeof(tmp_size));

	TEST_VAL(tmp_size, tmp_pImg1->GetSize());

	JDW_Image<JDW_Pixel, JDW_Pixel>* tmp_pImg2 = new JDW_Image<JDW_Pixel, JDW_Pixel>(tmp_size);
	fin.read((char *)(tmp_pImg2), sizeof(*tmp_pImg2));
	fin.close();
	TEST_TRUE(tmp_pImg1->GetPixel(iV2(0, 0)) == tmp_pImg2->GetPixel(iV2(0, 0)));
	TEST_TRUE(tmp_pImg1->GetPixel(iV2(1, 0)) == tmp_pImg2->GetPixel(iV2(1, 0)));
	TEST_TRUE(tmp_pImg1->GetPixel(iV2(0, 1)) == tmp_pImg2->GetPixel(iV2(0, 1)));
	TEST_TRUE(tmp_pImg1->GetPixel(iV2(1, 1)) == tmp_pImg2->GetPixel(iV2(1, 1)));
	TEST_TRUE(tmp_pImg1->GetPixel(iV2(0, 2)) == tmp_pImg2->GetPixel(iV2(0, 2)));
	TEST_TRUE(tmp_pImg1->GetPixel(iV2(1, 2)) == tmp_pImg2->GetPixel(iV2(1, 2)));
	TEST_TRUE(tmp_pImg1->GetTrans() == tmp_pImg2->GetTrans());
	TEST_TRUE(tmp_pImg1->GetSize() == tmp_pImg2->GetSize());
}

void TestSizes() {
	TEST_VAL(sizeof(unsigned char), 1);
	TEST_VAL(sizeof(char), 1);
	TEST_VAL(sizeof(unsigned short), 2);
	TEST_VAL(sizeof(short), 2);
	TEST_VAL(sizeof(unsigned int), 4);
	TEST_VAL(sizeof(int), 4);
	TEST_VAL(sizeof(double), 8);
	TEST_VAL(sizeof(long), 4);
}

void TestTypes() {
	ui8 tmp_ui8 = 255;
	i8 tmp_i8 = -128;
	i16 tmp_i16 = -32768;
	//ui32 tmp_ui32 = 4294967296;
	i32 tmp_i32 = 2147483647;
	d64 tmp_d64 = -1.1;

	TEST_VAL(tmp_ui8, 255);
	TEST_VAL(tmp_i8, -128);
//	TEST_VAL(tmp_ui16, 65536);
	TEST_VAL(tmp_i16, -32768);
//	TEST_VAL(tmp_ui32, 4294967296);
	TEST_VAL(tmp_i32, 2147483647);
	tmp_i32 = -2147483647;
	TEST_VAL(tmp_i32, -2147483647);
	TEST_VAL(tmp_d64, -1.1);
}

void TestImage() {
	JDW_Image<JDW_Pixel, JDW_Pixel>* tmp_pImg = new JDW_Image<JDW_Pixel, JDW_Pixel>(iV2(5, 5));

	TEST_TRUE(tmp_pImg->IsInside(iV2(0, 0)));
	TEST_TRUE(tmp_pImg->IsInside(iV2(0, 4)));
	TEST_TRUE(tmp_pImg->IsInside(iV2(4, 0)));
	TEST_TRUE(tmp_pImg->IsInside(iV2(4, 4)));

	TEST_FALSE(tmp_pImg->IsInside(iV2(-1, -1)));
	TEST_FALSE(tmp_pImg->IsInside(iV2(0, 5)));
	TEST_FALSE(tmp_pImg->IsInside(iV2(5, 0)));
	TEST_FALSE(tmp_pImg->IsInside(iV2(5, 5)));
	TEST_TRUE(tmp_pImg->IsInside(iV2(-1, 3)));

}
int main() {
	// All tests should go trough OK, and if so, no output be given.

	TestVector2d();
	TestVector3d();
	TestList();
	TestPixel();
	TestImage();
	TestIO();
	TestSizes();
	TestTypes();

	exit(0);
}
