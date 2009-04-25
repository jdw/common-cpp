/*
 * jdw_image.h
 *
 *  Created on: Apr 18, 2009
 *      Author: jdw
 */

#ifndef JDW_IMAGE
#define JDW_IMAGE

#include <vector>
#include "jdw_test.h"
#include <stdlib.h>
#include "jdw_types.h"
#include "jdw_pixel.h"
#include <boost/shared_ptr.hpp>

namespace JDW_PixelDrawMode {
	enum Enum {
		COPY = 0, // pixel[x][y] = in_pixel;
		ADD, // pixel[x][y] += in_pixel;
		ALPHA, // pixel[x][y].r = (255-in_pixel.a) * pixel[x][y].r + in_pixel.a * in_pixel.r;
		MULTI, // pixel[x][y] *= in_pixel;
		ONBLACKONLY, // if (pixel[x][y]->r == 0 && pixel[x][y]->g == 0 && pixel[x][y]->b == 0) pixel[x][y] = in_pixel;
		ONREDONLY, // if (pixel[x][y]->g == 0 && pixel[x][y]->b == 0) pixel[x][y] = in_pixel;
		ONGREENONLY, // if (pixel[x][y]->r == 0 && pixel[x][y]->b == 0) pixel[x][y] = in_pixel;
		ONBLUEONLY, // if (pixel[x][y]->r == 0 && pixel[x][y]->g == 0) pixel[x][y] = in_pixel;
		ONGREYONLY, // if (pixel[x][y]->r != 0 && pixel[x][y]->g != 0 && pixel[x][y]->b != 0) pixel[x][y] = in_pixel;
		ONWHITEONLY, // if (pixel[x][y]->r == 255 && pixel[x][y]->g == 255 && pixel[x][y]->b == 255) pixel[x][y] = in_pixel;

		MAX // Faulty
	};
}

template <class T, class U> // T = shared_ptr<U>
class JDW_Image {
public:
	JDW_Image(const iV2& in_size) {
		spSize = boost::shared_ptr<iV2>(new iV2(in_size));
		spPixel = boost::shared_ptr<std::vector<U> >(new std::vector<U>(spSize->x * spSize->y));

		for (int i = 0; i < spSize->x * spSize->y; ++i)
			(*spPixel)[i] =U();

		trans = U();
	}
/*
	JDW_Image(const iV2 in_size, T* in_pixel)
	: size(in_size), pixel(in_pixel) {
		trans = T();
	}
*/
	~JDW_Image() {
		//delete[] pixel;
	}

	void Blit(const iV2& in_offset, JDW_Image<T, U>* const in_pFrom, const JDW_PixelDrawMode::Enum in_mode = JDW_PixelDrawMode::COPY) {
		for (int y = 0; y < in_pFrom->GetSize().y; ++y)
			for (int x = 0; x < in_pFrom->GetSize().x; ++x)
				this->PutPixel(iV2(x + in_offset.x, y + in_offset.y),
					           in_pFrom->GetPixel(iV2(x, y)),
					           in_mode);
	}

	void PutPixel(const iV2& in_pos, const U& in_pixel, const JDW_PixelDrawMode::Enum in_mode = JDW_PixelDrawMode::COPY) {
		TEST_TRUE(in_mode < JDW_PixelDrawMode::MAX);
		if (!(IsInside(in_pos))) return;
		int tmp_pos = in_pos.x + spSize->x * in_pos.y;
		switch (in_mode) {
			case JDW_PixelDrawMode::COPY: (*spPixel)[tmp_pos] = in_pixel; break;
			case JDW_PixelDrawMode::ADD: (*spPixel)[tmp_pos].r += in_pixel.r; (*spPixel)[tmp_pos].g += in_pixel.g; (*spPixel)[tmp_pos].b += in_pixel.b; break;
			case JDW_PixelDrawMode::ALPHA: {
				double tmp_a = double(in_pixel.a);
				double tmp_ad = tmp_a / 255.0;

				double tmp_r, tmp_g, tmp_b;
				tmp_r = (1.0 - tmp_ad) * double((*spPixel)[tmp_pos].r) + tmp_ad * double(in_pixel.r);
				tmp_r = (tmp_r > 255)? 255: tmp_r;
				tmp_g = (1.0 - tmp_ad) * double((*spPixel)[tmp_pos].g) + tmp_ad * double(in_pixel.g);
				tmp_g = (tmp_r > 255)? 255: tmp_g;
				tmp_b = (1.0 - tmp_ad) * double((*spPixel)[tmp_pos].b) + tmp_ad * double(in_pixel.b);
				tmp_b = (tmp_r > 255)? 255: tmp_b;

				(*spPixel)[tmp_pos].r = int(tmp_r);
				(*spPixel)[tmp_pos].g = int(tmp_g);
				(*spPixel)[tmp_pos].b = int(tmp_b);
			} break;

			case JDW_PixelDrawMode::MULTI: (*spPixel)[tmp_pos].r *= in_pixel.r; (*spPixel)[tmp_pos].g *= in_pixel.g; (*spPixel)[tmp_pos].b *= in_pixel.b; break;
			case JDW_PixelDrawMode::ONBLACKONLY: if ((*spPixel)[tmp_pos].r == 0 && (*spPixel)[tmp_pos].g == 0 && (*spPixel)[tmp_pos].b == 0) (*spPixel)[tmp_pos] = in_pixel; break;
			case JDW_PixelDrawMode::ONREDONLY: if ((*spPixel)[tmp_pos].g == 0 && (*spPixel)[tmp_pos].b == 0) (*spPixel)[tmp_pos] = in_pixel; break;
			case JDW_PixelDrawMode::ONGREENONLY: if ((*spPixel)[tmp_pos].r == 0 && (*spPixel)[tmp_pos].b == 0) (*spPixel)[tmp_pos] = in_pixel; break;
			case JDW_PixelDrawMode::ONBLUEONLY: if ((*spPixel)[tmp_pos].r == 0 && (*spPixel)[tmp_pos].g == 0) (*spPixel)[tmp_pos] = in_pixel; break;
			case JDW_PixelDrawMode::ONGREYONLY: if ((*spPixel)[tmp_pos].r != 0 && (*spPixel)[tmp_pos].g != 0 && (*spPixel)[tmp_pos].b != 0) (*spPixel)[tmp_pos] = in_pixel; break;
			case JDW_PixelDrawMode::ONWHITEONLY: if ((*spPixel)[tmp_pos].r == 255 && (*spPixel)[tmp_pos].g == 255 && (*spPixel)[tmp_pos].b == 255) (*spPixel)[tmp_pos] = in_pixel; break;
			default: TEST_TRUE(FALSE); break; // If new modes are implemented, we will be told...
		}
	}

	U GetTrans() { return trans; }
	void SetTrans(const U& in) { trans = in; }
	std::vector<U>* GetPixels() { return spPixel.get(); }
	//std::vector<T> GetPixels() { return pixel; }
	//void SetPixels(T in_p) { pixel = in_p; }
	const U& GetPixel(const iV2& in_pos) { return (*spPixel)[in_pos.x + spSize->x * in_pos.y]; }
	const iV2& GetSize() { return (*spSize.get()); }
	void SetAlpha(const int& in_alpha) {
		if (in_alpha > 255) return;

		for (int i = 0; i < spSize->x * spSize->y; ++i)
			(*spPixel)[i].a = in_alpha;
	}

	void Fill(const T& in_color) {
		for (int i = 0; i < spSize->x * spSize->y; ++i)
			(*spPixel)[i].integer = in_color.integer;
	}

	bool IsInside(const iV2& in_pos) {
		if (!(0 <= in_pos.x && in_pos.x < spSize->x)) return FALSE;
		if (!(0 <= in_pos.y && in_pos.y < spSize->y)) return FALSE;

		return TRUE;
	}

	void DrawLine(const iV2& in_p0, const iV2& in_p1, const T& in_pixel, const JDW_PixelDrawMode::Enum in_mode = JDW_PixelDrawMode::COPY) {
		int deltax = abs(in_p1.x - in_p0.x);        // The difference between the x's
		int deltay = abs(in_p1.y - in_p0.y);        // The difference between the y's
		int x = in_p0.x;                       // Start x off at the first pixel
		int y = in_p0.y;                       // Start y off at the first pixel
		int xinc1 = 0;
		int xinc2 = 0;
		int yinc1 = 0;
		int yinc2 = 0;
		int den = 0;
		int num = 0;
		int numadd = 0;
		int numpixels = 0;
		int curpixel = 0;

		if (in_p1.x >= in_p0.x) { // The x-values are increasing
			xinc1 = 1;
			xinc2 = 1;
		}
		else { // The x-values are decreasing
			xinc1 = -1;
			xinc2 = -1;
		}

		if (in_p1.y >= in_p0.y) { // The y-values are increasing
			yinc1 = 1;
			yinc2 = 1;
		}
		else { // The y-values are decreasing
			yinc1 = -1;
			yinc2 = -1;
		}

		if (deltax >= deltay) { // There is at least one x-value for every y-value
			xinc1 = 0;                  // Don't change the x when numerator >= denominator
			yinc2 = 0;                  // Don't change the y for every iteration
			den = deltax;
			num = deltax / 2;
			numadd = deltay;
			numpixels = deltax;         // There are more x-values than y-values
		}
		else { // There is at least one y-value for every x-value
			xinc2 = 0;                  // Don't change the x for every iteration
			yinc1 = 0;                  // Don't change the y when numerator >= denominator
			den = deltay;
			num = deltay / 2;
			numadd = deltax;
			numpixels = deltay;         // There are more y-values than x-values
		}

		for (curpixel = 0; curpixel <= numpixels; curpixel++) {
			PutPixel(iV2(x, y), in_pixel, in_mode);             // Draw the current pixel
			num += numadd;              // Increase the numerator by the top of the fraction
			if (num >= den) {           // Check if numerator >= denominator
				num -= den;               // Calculate the new numerator value
				x += xinc1;               // Change the x as appropriate
				y += yinc1;               // Change the y as appropriate
			}
			x += xinc2;                 // Change the x as appropriate
			y += yinc2;                 // Change the y as appropriate
		}
	}

	boost::shared_ptr<iV2> spSize;
	boost::shared_ptr<std::vector<U> > spPixel;
	U trans;
};

typedef JDW_Image<JDW_Pixel, JDW_Pixel> Image;
typedef boost::shared_ptr<JDW_Image<SPPixel, JDW_Pixel> > SPImage;
//typedef JDW_Image<PixelToaster::TrueColorPixel> Image;

#endif
