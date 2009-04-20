#ifndef JDW_SCENE3D
#define JDW_SCENE3D

#include "jdw_scene.h"

template <class T>
class JDW_Scene3d: public JDW_Scene {
public:
	~JDW_Scene3d() {
	}

	int GetCamCount() const { return pCam->size(); }
	Camera<T>* GetCam(int i) { return pCam[i]; }
	int GetObjCount() const { return pObj->size(); }
	void AddObj(Cube<T>* in) { pObj->push_back(in); }
	void AddCam(Camera<T>* in) { pCam->push_back(in); }

	const bool& IsRolling() const { return isRolling; }

	virtual void Update() = 0;

protected:
	JDW_Scene3d() {
		POV = V3<T>(0, 0, 1);
		isRolling = true;
	}

	void Project(Vertex<T>& in_v, const T e) {
		/*
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
		*/
	}

	std::vector<Camera<T>*>* pCam;
	Camera<T>* pCurrentCam;
	std::vector<Cube<T>*>* pObj;
	V3<T> POV;
public:
	bool isRolling; // Scene still rolling (true) or finnished (false)

private:
};

#endif
