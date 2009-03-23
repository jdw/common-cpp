#ifndef JDW_CUBE
#define JDW_CUBE

#include "jdw_3dmath.h"
#include "../../pixeltoaster/PixelToaster.h"

template <class T>
class Cube {
public:
	Cube(V3<T>, T, PixelToaster::TrueColorPixel);
	~Cube();
	
	const V3<T>& GetOrigo() { return o; }
	T GetSide() { return sides; }
	T GetSize() { return sides * sides * sides; }
	const PixelToaster::TrueColorPixel& GetColor() { return clr; }
	Poly<T>** const GetPolys() { return pPolys; }
	Poly<T>* const GetPoly(int i) { return pPolys[i]; }
	int GetVertexCount() { return sizeof((*pVertexList)) / sizeof(Vertex<T>); }
	int GetPolyCount() { return sizeof((pPolys)) / sizeof(Poly<T>*); }
	Vertex<T>* GetVertexList() { return pVertexList; }
	// get polycount?
	
private:
	Vertex<T>* AddVertex(V3<T>);
	
	V3<T> o;
	T sides;
	PixelToaster::TrueColorPixel clr;
	Poly<T>* pPolys[12];
	Vertex<T>* pVertexList;
};

#endif
