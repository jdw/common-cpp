#include "jdw_screen.h"
#include <vector>

using namespace PixelToaster;

#define abs(x) (((x) > 0)? (x): -1 * (x))

Screen::Screen() {
	size = V2<int>(640, 480);
	std::vector<TrueColorPixel> pixels(size.x * size.y);
	
	pDisplay = new Display( "JDW's cube", size.x, size.y, Output::Windowed);
	drawAxis = false;
}

Screen::~Screen() {

}

void Screen::Update() {	
	if (drawAxis)
		DrawAxis();

	pDisplay->update(pixels);
	
	for (unsigned int i = 0; i < pixels.size(); i++) {
			pixels[i].r = 0;
			pixels[i].g = 0;
			pixels[i].b = 0;
		}
}

void Screen::PutPixel(const V2<int>& in) {
	V2<int> tmp = in;
	PutPixel(tmp.x, tmp.y);
}

void Screen::PutPixel(const int& in_x, const int& in_y) {
	if (!(in_x >= 0 && in_x < size.x)) return;
	if (!(in_y >= 0 && in_y < size.y)) return;

	if ((pixels[in_x + in_y * size.x].r + clr.r) > 255) pixels[in_x + in_y * size.x].r = 255;
	else pixels[in_x + in_y * size.x].r += clr.r;
	
	if (pixels[in_x + in_y * size.x].g + clr.g > 255) pixels[in_x + in_y * size.x].g = 255;
	else pixels[in_x + in_y * size.x].g += clr.g;
	
	if (pixels[in_x + in_y * size.x].b + clr.b > 255) pixels[in_x + in_y * size.x].b = 255;
	else pixels[in_x + in_y * size.x].b += clr.b;
}

// --- PRiVATE ---
void Screen::DrawAxis() {
	/*
	calc(*xAxis, 0.0f);	calc(*xAxis->pNext, 0.0f);
	calc(*yAxis, 0.0f);	calc(*yAxis->pNext, 0.0f);
	calc(*zAxis, 0.0f);	calc(*zAxis->pNext, 0.0f);
	clr = TrueColorPixel(200, 0, 0);
	DrawLine(xAxis->scr, xAxis->pNext->scr);
	clr = TrueColorPixel(200, 200, 0);
	DrawLine(yAxis->scr, yAxis->pNext->scr);
	clr = TrueColorPixel(0, 0, 200);
	drawLine(zAxis->scr, zAxis->pNext->scr);
	*/
}

void Screen::DrawLine(const V2<int>& in_p0, const V2<int>& in_p1) {
	//cout << x1 << "," << y1 << " " << x2 << "," << y2 << endl;
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
		if (num >= den)             // Check if numerator >= denominator
		{
			num -= den;               // Calculate the new numerator value
			x += xinc1;               // Change the x as appropriate
			y += yinc1;               // Change the y as appropriate
		}
		x += xinc2;                 // Change the x as appropriate
		y += yinc2;                 // Change the y as appropriate
	}
}
