#ifndef JDW_SCREEN
#define JDW_SCREEN

class JDW_Screen {
public:
	JDW_Screen(char* in_title, const iV2& in_size, bool in_fullscreen) {
		pDisplay = new PixelToaster::Display(in_title, size.x, size.y,
				               (in_fullscreen)? PixelToaster::Output::Fullscreen : PixelToaster::Output::Windowed);

		pImage = new JDW_Image<PixelToaster::TrueColorPixel>(in_size);

		pix = (PixelToaster::TrueColorPixel*)malloc(size.x * size.y * sizeof(PixelToaster::TrueColorPixel));
		for (int i = 0; i < size.x * size.y; ++i)
			pix[i] = PixelToaster::TrueColorPixel();

		drawAxis = false;
	}

	~JDW_Screen() {
	}

	void Update() {
		//if (drawAxis) DrawAxis();
		pDisplay->update(pix);

		pImage->Black();
	}

	bool Open() { return pDisplay->open(); }
	JDW_Image<PixelToaster::TrueColorPixel>* GetImage() { return pImage; }
private:
	PixelToaster::Display* pDisplay;
	PixelToaster::TrueColorPixel* pix;
	JDW_Image<PixelToaster::TrueColorPixel>* pImage;
	PixelToaster::TrueColorPixel clr; // Color to draw with
	iV2 size;
	bool drawAxis;
};

#endif
