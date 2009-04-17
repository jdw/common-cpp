/*
 * jdw_test.h
 *
 *  Created on: Apr 16, 2009
 *      Author: jdw
 */

#ifndef JDW_TEST_H_
#define JDW_TEST_H_

#include <iostream>
#include "jdw_misc.h"

#define TEST_TRUE(x)\
	if ((x) != TRUE) {\
		std::cout << "Error in: " << __FILE__ << ":" << __LINE__ << " in (func.: " << __FUNCTION__ << ")." << std::endl;\
		std::cout << "Tested  : '" << #x << std::endl;\
		std::cout << "Expected: 'TRUE'" << std::endl;\
		exit(1);\
	}

#define TEST_FALSE(x)\
	if ((x) != FALSE) {\
		std::cout << "Error in: " << __FILE__ << ":" << __LINE__ << " in (func.: " << __FUNCTION__ << ")." << std::endl;\
		std::cout << "Tested  : '" << #x << "'." << std::endl;\
		std::cout << "Expected: 'FALSE'" << std::endl;\
		exit(1);\
	}

#define TEST_VAL(x, y)\
	if ((x) != (y)) {\
		std::cout << "Error in: " << __FILE__ << ":" << __LINE__ << " in (func.: " << __FUNCTION__ << ")" << std::endl;\
		std::cout << "Tested  : " << #x << std::endl;\
		std::cout << "Expected: " << #y << std::endl;\
		exit(1);\
	}

#define TEST_PTR(x)\
	if ((x) == NULL) {\
		std::cout << "Error in: " << __FILE__ << ":" << __LINE__ << " in (func.: " << __FUNCTION__ << ")" << std::endl;\
		std::cout << "Tested  : " << #x << "" << std::endl;\
		std::cout << "Expected: != NULL" << std::endl;\
		exit(1);\
	}

#endif /* JDW_TEST_H_ */
