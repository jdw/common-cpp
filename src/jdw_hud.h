#ifndef JDW_HUD
#define JDW_HUD

class HUD {
public:
	HUD();
	~HUD();
	
	void SetDrawFPS(bool in) { drawFPS = in; }
	
	void Update();
	
private:
	void DrawFPS();
	void DrawMessage();
	
	bool drawFPS;
	bool drawMessage;
	int* font[256];
};
#endif
