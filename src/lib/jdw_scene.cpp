// SiC: Remove this file from lib

#include "jdw_3dmath.h"
#include "jdw_camera.h"
#include "jdw_scene.h"
#include <vector>
#include <cmath>

template <class T>
Scene<T>::Scene() {
	POV = V3<T>(0, 0, 1);
}

template <class T>
Scene<T>::~Scene() {

}

template <class T>
int Scene<T>::GetCamCount() const {
	return pCam->size();
}

template <class T>
Camera<T>* Scene<T>::GetCam(int i) {
	return pCam[i];
}

template <class T>
int Scene<T>::GetObjCount() const {
	return pObj->size();
}

template <class T>
void Scene<T>::AddObj(Cube<T>* in) {
	pObj->push_back(in);
}

template <class T>
void Scene<T>::AddCam(Camera<T>* in) {
	pCam->push_back(in);
}

template <class T>
void Scene<T>::Project(Vertex<T>& in_v, const T e) {
	V3<T> cr = pCurrentCam->GetRot();
	V3<T> cp = pCurrentCam->GetPos();
	V3<T> v = pCurrentCam->GetPos() - POV;
	V3<T> d();

	/// Projection
	d.x = cos(cr.y) * (sin(cr.z) * (in_v.pos.y - cp.y) + cos(cr.z) * (in_v.pos.x - cp.x)) - sin(cr.y) * (in_v.pos.z - cp.z);
	d.y = sin(cr.x) * (cos(cr.y) * (in_v.pos.z - cp.z) + sin(cr.y) * (sin(cr.z) * (in_v.pos.y - cp.y) + cos(cr.z) * (in_v.pos.x - cp.x))) + cos(cr.x) * (cos(cr.z) * (in_v.pos.y - cp.y) - sin(cr.z) * (in_v.pos.x - cp.x));
	d.z = cos(cr.x) * (cos(cr.y) * (in_v.pos.z - cp.z) + sin(cr.y) * (sin(cr.z) * (in_v.pos.y - cp.y) + cos(cr.z) * (in_v.pos.x - cp.x))) - sin(cr.x) * (cos(cr.z) * (in_v.pos.y - cp.y) - sin(cr.z) * (in_v.pos.x - cp.x));

	if (d.z == 0.0f) d.z = 1.0f;
	in_v.scr.x = (d.x - v.x) * (v.z / d.z);
	in_v.scr.y = (d.y - v.y) * (v.z / d.z);

	in_v.calculated = true;
}

