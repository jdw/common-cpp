#ifndef JDW_SCREEN
#define JDW_SCREEN

#include "../common-cpp/jdw_3dmath.h"
#include "../pixeltoaster/PixelToaster.h"

class Screen {
public:
	Screen();
	~Screen();
	
	void Update();
	void PutPixel(const V2<int>& in);
	void PutPixel(const int& in_x, const int& in_y);
	
private:
	void DrawAxis();

	PixelToaster::Display* pDisplay;
	std::vector<TrueColorPixel> pixels;
	PixelToaster::TrueColorPixel clr; // Color to draw with
	
	V2<int>* pSize;
	bool drawAxis;
}

#endif
