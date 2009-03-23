#ifndef JDW_V2
#define JDW_V2
template <class T>
class V2 {
public:	
	V2(T in_x, T in_y) {
		this->x = in_x;
		this->y = in_y;
	}
	
	V2() {
		this->x = (T)0;
		this->y = (T)0;
	}
	
	T GetDP(const V2& in) const { // Dot-product
		return this->x * in.x + this->y * in.y;
	}
	
	V2 GetXP(const V2& in) const { // Cross-prodcut
		return V2(this->x * in.x, this->y * in.y);
	}
	
	T GetLength() const { // Gets length of vector
		return sqrt(this->GetDP(*this));
	}
	
	T GetDist(const V2& in) { // Returns distance between two vectors
		T dX = this->x - in.x;
		T dY = this->y - in.y;
		
		return sqrt(dX * dX + dY * dY);
	}
	
	V2 GetUnit() {
		T length = this->GetLength();
		return V2(this->x / length, this->y / length);
	}
	
	void operator=(const V2<T>& in) {
		this->x = in.x;
		this->y = in.y;
	}

	bool operator==(const V2<T>& in) const {
		if (this->x != in.x) return false;
		if (this->y != in.y) return false;
		
		return true;
	}

	bool operator!=(const V2<T>& in) const {
		if (this->x == in.x) return false;
		if (this->y == in.y) return false;
		
		return true;
	}

	void operator+=(const V2<T>& in) {
		this->x += in.x;
		this->y += in.y;
	}
	
	V2<T> operator+(const V2<T>& in) const {
		return V2<T>(this->x + in.x, this->y + in.y);
	}
	
	void operator-=(const V2<T>& in) {
		this->x -= in.x;
		this->y -= in.y;
	}

	V2<T> operator-(const V2<T>& in) const {
		return V2<T>(this->x - in.x, this->y - in.y);
	}

	void operator*=(const T& in) {
		this->x *= in;
		this->y *= in;
	}

	V2<T> operator*(const T& in) const {
		return V2<T>(this->x * in, this->y * in);
	}

	T x, y;
};
#endif

#ifndef JDW_V3
#define JDW_V3
template <class T>
class V3 {
public:	
	V3(T in_x, T in_y, T in_z) {
		this->x = in_x;
		this->y = in_y;
		this->z = in_z;
	}
	
	V3() {
		this->x = (T)0;
		this->y = (T)0;
		this->z = (T)0;
	}
	
	T GetDP(const V3<T> in) const { // Dot-product
		return this->x * in.x + this->y * in.y + this->z * in.z;
	}
	
	V3 GetXP(const V3<T>& in) const { // Cross-prodcut
		// A x B -> A=this, B=in
		return V3<T>((this->y * in.z) - (this->z * in.y),
		             (this->z * in.x) - (this->x * in.z),
		             (this->x * in.y) - (this->y * in.x));
	}
	
	T GetLength() const { // Gets length of vector
		return sqrt(this->GetDP(*this));
	}
	
	T GetDist(const V3& in) const { // Returns distance between two vectors
		T dX = this->x - in.x;
		T dY = this->y - in.y;
		T dZ = this->z - in.z;
		return sqrt(dX * dX + dY * dY + dZ * dZ);
	}
	
	V3 GetUnit() const { // Returns a unit vector
		T length = this->GetLength();
		return V3(this->x / length, this->y / length, this->z / length);
	}
	
	void operator=(const V2<T>& in) {
		this->x = in.x;
		this->y = in.y;
		this->z = in.z;
	}

	bool operator==(const V2<T>& in) const {
		if (this->x != in.x) return false;
		if (this->y != in.y) return false;
		if (this->z != in.z) return false;

		return true;
	}

	bool operator!=(const V2<T>& in) const {
		if (this->x == in.x) return false;
		if (this->y == in.y) return false;
		if (this->z == in.z) return false;

		return true;
	}

	void operator+=(const V2<T>& in) {
		this->x += in.x;
		this->y += in.y;
		this->z += in.z;
	}
	
	V2<T> operator+(const V2<T>& in) const {
		return V2<T>(this->x + in.x, this->y + in.y, this->z + in.z);
	}
	
	void operator-=(const V2<T>& in) {
		this->x -= in.x;
		this->y -= in.y;
		this->z -= in.z;
	}

	V2<T> operator-(const V2<T>& in) const {
		return V2<T>(this->x - in.x, this->y - in.y, this->z - in.z);
	}

	void operator*=(const T& in) {
		this->x *= in;
		this->y *= in;
		this->z *= in;
	}

	V2<T> operator*(const T& in) const {
		return V2<T>(this->x * in, this->y * in, this->z * in);
	}

	T x, y, z;
};
#endif

#ifndef JDW_VERTEX
#define JDW_VERTEX
template <class T>
struct Vertex {
	Vertex() {
		this->pos.x = (T)0;
		this->pos.y = (T)0;
		this->pos.z = (T)0;
		this->scr.x = (T)0;
		this->scr.y = (T)0;
		
		calculated = false;
		pNext = (Vertex<float>*)0;
	}
	
	Vertex(V3<T> in_pos, V2<int> in_scr) {
		this->pos = in_pos;
		this->scr = in_scr;
		
		calculated = false;
		pNext = (Vertex<float>*)0;
	}
	
	void Rotate(const float e)	{
		V3<float> tmp(in_v.pos.x, in_v.pos.y, in_v.pos.z);
		float tmp_cosE = cos(e);
		float tmp_sinE = sin(e);

		/// Rotation (http://www.siggraph.org/education/materials/HyperGraph/modeling/mod_tran/3drota.htm)
		// Round the x-axis
		in_v.pos.y = tmp_cosE * tmp.y - tmp_sinE * tmp.z;
		in_v.pos.z = tmp_sinE * tmp.y + tmp_cosE * tmp.z;

		// Round the y-axis
		tmp = in_v.pos;
		//in_v.pos.x = tmp_sinE * tmp.z + tmp_cosE * tmp.x;
		//in_v.pos.z = tmp_cosE * tmp.z - tmp_sinE * tmp.x;

		// Round the z-axis
		tmp = in_v.pos;
		//in_v.pos.x = tmp_cosE * tmp.x - tmp_sinE * tmp.y;
		//in_v.pos.y = tmp_sinE * tmp.x + tmp_cosE * tmp.y;
	}
		
	V3<T> pos;
	V2<int> scr;
	bool calculated;
	Vertex* pNext;
};
#endif

#ifndef JDW_POLY
#define JDW_POLY

#include "../pixeltoaster/PixelToaster.h"

template <class T>
class Poly {
public:	
	Poly(Vertex<T>* in_o, Vertex<T>* in_a, Vertex<T>* in_b) {
		this->o = in_o; // Keep 'em counterclockwise!
		this->a = in_a;
		this->b = in_b;
		
		clr = PixelToaster::TrueColorPixel(0, 87 , 0);
		
	}

	Poly(Vertex<T> in_o, Vertex<T> in_a, Vertex<T> in_b) {
		this->o = new Vertex<T>(in_o); // Keep 'em counterclockwise!
		this->a = new Vertex<T>(in_a);
		this->b = new Vertex<T>(in_b);
		
		clr = PixelToaster::TrueColorPixel(0, 87 , 0);
		
	}
	
	V3<T> GetNormal() {
		//normal = (p1-p2) x (p3-p2) dvs,
		//normal = (a - o) x (b - o) 
		//return (V3<T>(a->pos.x - o->pos.x, a->pos.y - o->pos.y, a->pos.z - o->pos.z).GetXP(
		//        V3<T>(b->pos.x - o->pos.x, b->pos.y - o->pos.y, b->pos.z - o->pos.z))).GetUnit();
		
		// http://easyweb.easynet.co.uk/~mrmeanie/plane/planes.htm
		V3<T> N((T)0, (T)0, (T)0), U((T)0, (T)0, (T)0), V((T)0, (T)0, (T)0);
		U.x = a->pos.x - o->pos.x;
		U.y = a->pos.y - o->pos.y;
		U.z = a->pos.z - o->pos.z;
		
		V.x = b->pos.x - o->pos.x;
		V.y = b->pos.y - o->pos.y;
		V.z = b->pos.z - o->pos.z;
		
		N.x = (U.y * V.z) - (U.z * V.y);
		N.y = (U.z * V.x) - (U.x * V.z);
		N.z = (U.x * V.y) - (U.y * V.x);
		
		return N.GetUnit();
		
	}
	
	T GetK(const V3<T>& p) {
		return this->GetNormal().DP(p);
	}
	
	Vertex<T>* o;
	Vertex<T>* a;
	Vertex<T>* b;
	PixelToaster::TrueColorPixel clr;
};
#endif
