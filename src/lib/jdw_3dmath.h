#ifndef JDW_POLY
#define JDW_POLY

//#include "../pixeltoaster/PixelToaster.h"

#ifdef __cplusplus
extern "C" {
#endif

template <class T>
class Poly {
public:	
	Poly(Vertex<T>* in_o, Vertex<T>* in_a, Vertex<T>* in_b);
	Poly(Vertex<T> in_o, Vertex<T> in_a, Vertex<T> in_b);
	
	V3<T> GetNormal();
	T GetK(const V3<T>& p);
	
	Vertex<T>* o;
	Vertex<T>* a;
	Vertex<T>* b;
	//PixelToaster::TrueColorPixel clr;
};

#ifdef __cplusplus
}
#endif

#endif
