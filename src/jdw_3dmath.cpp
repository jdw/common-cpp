/**
	* Class: V2
	* Author: Johannes Wirde
	* License: See LICENSE in source dir
	*/

#include "jdw_3dmath.h"	
// ------ CONSTRUCTOR/DESTRUCTOR -----------------------------------------------
template <class T>
V2<T>::V2(T in_x, T in_y) {
	this->x = in_x;
	this->y = in_y;
}

template <class T>
V2<T>::V2() {
	this->x = (T)0;
	this->y = (T)0;
}

// ------ PUBLiC ---------------------------------------------------------------
template <class T>
T V2<T>::GetDP(const V2& in) const { // Dot-product
	return this->x * in.x + this->y * in.y;
}

template <class T>
V2<T> V2<T>::GetXP(const V2& in) const { // Cross-prodcut
	return V2<T>(this->x * in.x, this->y * in.y);
}

template <class T>
T V2<T>::GetLength() const { // Gets length of vector
	return sqrt(this->GetDP(*this));
}

template <class T>
T V2<T>::GetDist(const V2& in) { // Returns distance between two vectors
	T dX = this->x - in.x;
	T dY = this->y - in.y;
	
	return sqrt(dX * dX + dY * dY);
}

template <class T>
V2<T> V2<T>::GetUnit() {
	T length = this->GetLength();
	return V2<T>(this->x / length, this->y / length);
}

// ------ PROTECTED ------------------------------------------------------------
// ------ PRiVATE --------------------------------------------------------------
// ------ OPERATORS ------------------------------------------------------------
template <class T>
void V2<T>::operator=(const V2<T>& in) {
	this->x = in.x;
	this->y = in.y;
}

template <class T>
bool V2<T>::operator==(const V2<T>& in) const {
	if (this->x != in.x) return false;
	if (this->y != in.y) return false;
	
	return true;
}

template <class T>
bool V2<T>::operator!=(const V2<T>& in) const {
	if (this->x == in.x) return false;
	if (this->y == in.y) return false;
	
	return true;
}

template <class T>
void V2<T>::operator+=(const V2<T>& in) {
	this->x += in.x;
	this->y += in.y;
}

template <class T>
V2<T> V2<T>::operator+(const V2<T>& in) const {
	return V2<T>(this->x + in.x, this->y + in.y);
}

template <class T>
void V2<T>::operator-=(const V2<T>& in) {
	this->x -= in.x;
	this->y -= in.y;
}

template <class T>
V2<T> V2<T>::operator-(const V2<T>& in) const {
	return V2<T>(this->x - in.x, this->y - in.y);
}

template <class T>
void V2<T>::operator*=(const T& in) {
	this->x *= in;
	this->y *= in;
}

template <class T>
V2<T> V2<T>::operator*(const T& in) const {
	return V2<T>(this->x * in, this->y * in);
}

/**
	* Class: V3
	* Author: Johannes Wirde
	* License: See LICENSE in source dir
	*/
	
// ------ CONSTRUCTOR/DESTRUCTOR -----------------------------------------------
template <class T>
V3<T>::V3(T in_x, T in_y, T in_z) {
	this->x = in_x;
	this->y = in_y;
	this->z = in_z;
}

template <class T>
V3<T>::V3() {
	this->x = (T)0;
	this->y = (T)0;
	this->z = (T)0;
}

// ------ PUBLiC ---------------------------------------------------------------
template <class T>
T V3<T>::GetDP(const V3<T> in) const { // Dot-product
	return this->x * in.x + this->y * in.y + this->z * in.z;
}

template <class T>
V3<T> V3<T>::GetXP(const V3<T>& in) const { // Cross-prodcut
	// A x B -> A=this, B=in
	return V3<T>((this->y * in.z) - (this->z * in.y),
	             (this->z * in.x) - (this->x * in.z),
	             (this->x * in.y) - (this->y * in.x));
}

template <class T>
T V3<T>::GetLength() const { // Gets length of vector
	return sqrt(this->GetDP(*this));
}

template <class T>
T V3<T>::GetDist(const V3& in) const { // Returns distance between two vectors
	T dX = this->x - in.x;
	T dY = this->y - in.y;
	T dZ = this->z - in.z;
	return sqrt(dX * dX + dY * dY + dZ * dZ);
}

template <class T>
V3<T> V3<T>::GetUnit() const { // Returns a unit vector
	T length = this->GetLength();
	return V3<T>(this->x / length, this->y / length, this->z / length);
}

// ------ PROTECTED ------------------------------------------------------------
// ------ PRiVATE --------------------------------------------------------------
// ------ OPERATORS ------------------------------------------------------------
template <class T>
void V3<T>::operator=(const V3<T>& in) {
	this->x = in.x;
	this->y = in.y;
	this->z = in.z;
}

template <class T>
bool V3<T>::operator==(const V3<T>& in) const {
	if (this->x != in.x) return false;
	if (this->y != in.y) return false;
	if (this->z != in.z) return false;

	return true;
}

template <class T>
bool V3<T>::operator!=(const V3<T>& in) const {
	if (this->x == in.x) return false;
	if (this->y == in.y) return false;
	if (this->z == in.z) return false;

	return true;
}

template <class T>
void V3<T>::operator+=(const V3<T>& in) {
	this->x += in.x;
	this->y += in.y;
	this->z += in.z;
}

template <class T>
V3<T> V3<T>::operator+(const V3<T>& in) const {
	return V3<T>(this->x + in.x, this->y + in.y, this->z + in.z);
}

template <class T>
void V3<T>::operator-=(const V3<T>& in) {
	this->x -= in.x;
	this->y -= in.y;
	this->z -= in.z;
}

template <class T>
V3<T> V3<T>::operator-(const V3<T>& in) const {
	return V3<T>(this->x - in.x, this->y - in.y, this->z - in.z);
}

template <class T>
void V3<T>::operator*=(const T& in) {
	this->x *= in;
	this->y *= in;
	this->z *= in;
}

template <class T>
V3<T> V3<T>::operator*(const T& in) const {
	return V3<T>(this->x * in, this->y * in, this->z * in);
}

/**
	* Class: Vertex
	* Author: Johannes Wirde
	* License: See LICENSE in source dir
	*/
	
// ------ CONSTRUCTOR/DESTRUCTOR -----------------------------------------------
template <class T>
Vertex<T>::Vertex() {
	this->pos.x = (T)0;
	this->pos.y = (T)0;
	this->pos.z = (T)0;
	this->scr.x = 0;
	this->scr.y = 0;
	
	calculated = false;
	pNext = (Vertex<T>*)0;
}

// ------ PUBLiC ---------------------------------------------------------------
template <class T>
Vertex<T>::Vertex(V3<T> in_pos, V2<int> in_scr) {
	this->pos = in_pos;
	this->scr = in_scr;
	
	calculated = false;
	pNext = (Vertex<T>*)0;
}

template <class T>
void Vertex<T>::Rotate(const T e){
	V3<T> tmp = pos;
	float tmp_cosE = cos(e);
	float tmp_sinE = sin(e);

	/// Rotation (http://www.siggraph.org/education/materials/HyperGraph/modeling/mod_tran/3drota.htm)
	// Round the x-axis
	pos.y = tmp_cosE * tmp.y - tmp_sinE * tmp.z;
	pos.z = tmp_sinE * tmp.y + tmp_cosE * tmp.z;

	// Round the y-axis
	tmp = pos;
	//in_v.pos.x = tmp_sinE * tmp.z + tmp_cosE * tmp.x;
	//in_v.pos.z = tmp_cosE * tmp.z - tmp_sinE * tmp.x;

	// Round the z-axis
	tmp = pos;
	//in_v.pos.x = tmp_cosE * tmp.x - tmp_sinE * tmp.y;
	//in_v.pos.y = tmp_sinE * tmp.x + tmp_cosE * tmp.y;
	
	pos = tmp;
}

// ------ PROTECTED ------------------------------------------------------------
// ------ PRiVATE --------------------------------------------------------------
// ------ OPERATORS ------------------------------------------------------------

/**
	* Class: V3
	* Author: Johannes Wirde
	* License: See LICENSE in source dir
	*/

//#include "../pixeltoaster/PixelToaster.h"
	
// ------ CONSTRUCTOR/DESTRUCTOR -----------------------------------------------
template <class T>
Poly<T>::Poly(Vertex<T>* in_o, Vertex<T>* in_a, Vertex<T>* in_b) {
	this->o = in_o; // Keep 'em counterclockwise!
	this->a = in_a;
	this->b = in_b;
	
	//clr = PixelToaster::TrueColorPixel(0, 87 , 0);
}

template <class T>
Poly<T>::Poly(Vertex<T> in_o, Vertex<T> in_a, Vertex<T> in_b) {
	this->o = new Vertex<T>(in_o); // Keep 'em counterclockwise!
	this->a = new Vertex<T>(in_a);
	this->b = new Vertex<T>(in_b);
	
	//clr = PixelToaster::TrueColorPixel(0, 87 , 0);
}

// ------ PUBLiC ---------------------------------------------------------------
template <class T>
V3<T> Poly<T>::GetNormal() {
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

template <class T>
T Poly<T>::GetK(const V3<T>& p) {
	return this->GetNormal().DP(p);
}

// ------ PROTECTED ------------------------------------------------------------
// ------ PRiVATE --------------------------------------------------------------
// ------ OPERATORS ------------------------------------------------------------

