/**
	* Class:
	* Author:
	* License:
	*/

// ------ iNCLUDE --------------------------------------------------------------
#include "jdw_camera.h"

// ------ CONSTRUCTOR/DESTRUCTOR -----------------------------------------------
template <class T>
Camera<T>::Camera() {
	this->pos = V3<T>();
	this->tar = V3<T>();
	this->rot = V3<T>();
	Update();
}

template <class T>
Camera<T>::Camera(V3<T> in_pos, V3<T> in_tar) {
	this->pos = in_pos;
	this->tar = in_tar;
	this->rot = V3<T>();
	Update();
}

template <class T>
Camera<T>::~Camera() {

}

// ------ PUBLiC ---------------------------------------------------------------
template <class T>
const V3<T>& Camera<T>::GetPos() const {
	return this->pos;
}

template <class T>
const V3<T>& Camera<T>::GetTar() const {
	return this->tar;
}

template <class T>
const V3<T>& Camera<T>::GetRot() const {
	return this->rot;
}

template <class T>
void Camera<T>::SetPos(const V3<T>& in) {
	this->pos = in;
}

template <class T>
void Camera<T>::SetTar(const V3<T>& in) {
	this->tar = in;
}

template <class T>
void Camera<T>::SetRot(const V3<T>& in) {
	this->rot = in;
}

template <class T>
void Camera<T>::Update() {
	// Update camera rotation
	V3<T> N((T)0, (T)0, (T)0);
	
	N.x = (pos.y * tar.z) - (pos.z * tar.y);
	N.y = (pos.z * tar.x) - (pos.x * tar.z);
	N.z = (pos.x * tar.y) - (pos.y * tar.x);
	
	N = N.GetUnit();
	
	rot.x = cos(N.x);
	rot.y = sin(N.y);
	rot.z = tan(N.z);
}

// ------ PROTECTED ------------------------------------------------------------
// ------ PRiVATE --------------------------------------------------------------
// ------ OPERATORS ------------------------------------------------------------
