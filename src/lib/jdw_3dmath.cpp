


/**
	* Class: Poly
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

