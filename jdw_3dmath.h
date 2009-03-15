#ifndef JDW_V2
#define JDW_V2
template <class T>
class v2 {
public:	
	v2(T in_x, T in_y) {
		this->x = in_x;
		this->y = in_y;
	}
	
	v2() {
		this->x = (T)0;
		this->y = (T)0;
	}
	
	T DP(const v2& in) { // Dot-product
		return this->x * in.x + this->y * in.y;
	}
	
	v2 XP(const v2& in) { // Cross-prodcut
		return v2(this->x * in.x, this->y * in.y);
	}
	
	T GetLength() { // Gets length of vector
		return sqrt(this->DP(*this));
	}
	
	T GetDist(const v2& in) { // Returns distance between two vectors
		T dX = this->x - in.x;
		T dY = this->y - in.y;
		
		return sqrt(dX * dX + dY * dY);
	}
	
	v2 GetUnit() {
		T length = this->GetLength();
		
		return v2(this->x / length, this->y / length);
	}
	
	
	T x, y;
};
#endif

#ifndef JDW_V3
#define JDW_V3
template <class T>
class v3 {
public:	
	v3(T in_x, T in_y, T in_z) {
		this->x = in_x;
		this->y = in_y;
		this->z = in_z;
	}
	
	v3() {
		this->x = (T)0;
		this->y = (T)0;
		this->z = (T)0;
	}
	
	T DP(const v3<T> in) { // Dot-product
		return this->x * in.x + this->y * in.y + this->z * in.z;
	}
	
	v3 XP(const v3<T>& in) { // Cross-prodcut
		// A x B -> A=this, B=in
		return v3<T>((this->y * in.z) - (this->z * in.y),
		             (this->z * in.x) - (this->x * in.z),
		             (this->x * in.y) - (this->y * in.x));
	}
	
	T GetLength() { // Gets length of vector
		return sqrt(this->DP(*this));
	}
	
	T GetDist(const v3& in) { // Returns distance between two vectors
		T dX = this->x - in.x;
		T dY = this->y - in.y;
		T dZ = this->z - in.z;
		
		return sqrt(dX * dX + dY * dY + dZ * dZ);
	}
	
	v3 GetUnit() { // Returns a unit vector
		T length = this->GetLength();
		
		return v3(this->x / length, this->y / length, this->z / length);
	}
	
	
	T x, y, z;
};
#endif

#ifndef JDW_VERTEX
#define JDW_VERTEX
template <class T>
struct vertex {
	vertex() {
		this->pos.x = (T)0;
		this->pos.y = (T)0;
		this->pos.z = (T)0;
		this->scr.x = (T)0;
		this->scr.y = (T)0;
		
		calculated = false;
		pNext = (vertex<float>*)0;
	}
	
	v3<T> pos;
	v2<int> scr;
	bool calculated;
	vertex* pNext;
};
#endif

#ifndef JDW_POLY
#define JDW_POLY

#include "PixelToaster.h"

template <class T>
class poly {
public:	
	poly(vertex<T>* in_o, vertex<T>* in_a, vertex<T>* in_b) {
		this->o = in_o; // Keep 'em counterclockwise!
		this->a = in_a;
		this->b = in_b;
		
		clr = PixelToaster::TrueColorPixel(0, 87 , 0);
		
	}
	
	v3<T> GetNormal() {
		//normal = (p1-p2) x (p3-p2) dvs,
		//normal = (a - o) x (b - o) 
		return (v3<T>(a->pos.x - o->pos.x, a->pos.y - o->pos.y, a->pos.z - o->pos.z).XP(
		        v3<T>(b->pos.x - o->pos.x, b->pos.y - o->pos.y, b->pos.z - o->pos.z))).GetUnit();
	}
	
	T GetK(const v3<T>& p) {
		return this->GetNormal().DP(p);
	}
	
	vertex<T>* o;
	vertex<T>* a;
	vertex<T>* b;
	PixelToaster::TrueColorPixel clr;
};
#endif
