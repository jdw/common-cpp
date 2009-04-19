/*
 * jdw_image.h
 *
 *  Created on: Apr 18, 2009
 *      Author: jdw
 */

#ifndef JDW_IMAGE
#define JDW_IMAGE

template <class T>
class JDW_Image {
public:
	JDW_Image(const iV2 in_size)
	: size(in_size) {
		pixel = (T*)malloc(size.x * size.y * sizeof(T));
		for (int i = 0; i < size.x * size.y; ++i)
			pixel[i] = T();
	}

	JDW_Image(const iV2 in_size, T* in_pixel)
	: size(in_size), pixel(in_pixel) {
		for (int i = 0; i < size.x * size.y; ++i)
			pixel[i] = T();
	}

	~JDW_Image() {
		delete[] pixel;
	}

	void Blit(const iV2& in_offset, JDW_Image* in_pFrom) {
		for (int y = 0; y < in_pFrom->GetSize().y; ++y)
			for (int x = 0; x < in_pFrom->GetSize().x; ++x)
				if (this->IsInside(iV2(x + in_offset.x, y + in_offset.y))) // iv2 + iv2?
					this->PutPixel(iV2(x + in_offset.x, y + in_offset.y), in_pFrom->GetPixel(iV2(x, y)));
	}

	void PutPixel(const iV2 in_pos, const T& in_pixel) { pixel[in_pos.x + size.x * in_pos.y] = in_pixel; }
	T GetTrans() { return trans; }
	T* GetPixels() { return pixel; }
	void SetTrans(const T& in) { trans = in; }
	const T& GetPixel(const iV2 in_pos) { return pixel[in_pos.x + size.x * in_pos.y]; }
	const iV2& GetSize() { return size; }

	void Black() {
		for (int i = 0; i < size.x * size.y; ++i)
			pixel[i].integer = 0;
	}

	bool IsInside(const iV2& in_pos) {
		if (!(0 <= in_pos.x && in_pos.x < size.x)) return FALSE;
		if (!(0 <= in_pos.y && in_pos.y < size.y)) return FALSE;

		return TRUE;
	}

	void DrawLine(const iV2& in_p0, const iV2& in_p1) {
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
			PutPixel(x, y);             // Draw the current pixel
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

	const iV2 size;
	T* pixel;
	T trans;
};

typedef JDW_Image<PixelToaster::TrueColorPixel> Image;

#endif
