#ifndef JDW_HUD
#define JDW_HUD

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif
