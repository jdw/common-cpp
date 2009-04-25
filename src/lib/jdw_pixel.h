/*
 * jdw_pixel.h
 *
 *  Created on: Apr 22, 2009
 *      Author: jdw
 */

#ifndef JDW_PIXEL
#define JDW_PIXEL

#include <boost/shared_ptr.hpp>

union JDW_Pixel {
	JDW_Pixel() {
		integer = 0;
	}

	JDW_Pixel(ui8 in_r, ui8 in_g, ui8 in_b, ui8 in_a = 0) {
		this->r = in_r;
		this->g = in_g;
		this->b = in_b;
		this->a = in_a;
	}

	ui32 integer;
	struct {
		//ui8 a,r,g,b;
		ui8 b,g,r,a;
	};

	bool operator==(const JDW_Pixel& in) const {
		if (this->r != in.r) return false;
		if (this->g != in.g) return false;
		if (this->b != in.b) return false;
		if (this->a != in.a) return false;

		return true;
	}

	bool operator!=(const JDW_Pixel& in) const {
		return !(*this == in);
	}
};

typedef JDW_Pixel Pixel;
typedef boost::shared_ptr<JDW_Pixel> SPPixel;

#endif
