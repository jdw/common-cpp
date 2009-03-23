#ifndef JDW_SCENE
#define JDW_SCENE

#include "jdw_3dmath.h"
#include "jdw_camera.h"
#include <vector>

#include "cube.h"

template <class T>
class Scene {
public:
	Scene() {
	
	}
	
	~Scene() {
	}
	
	int GetCamCount() const { return pCam->size(); }
	Camera<T>* GetCam(int i) { return pCam[i]; }
	int GetObjCount() const { return pObj->size(); }
	
	void AddObj(Cube* in) { pObj->push_back(in); }
	void AddCam(Camera* in) { pCam->push_back(in); }
	
private:
	void Project(Vertex<float>& in_v, const float e)	{
		V3<float> cr = pCurrentCam->GetRot();
		V3<float> cp = pCurrentCam->GetPos();
		V3<float> d();
		
		/// Projection
		d.x = cos(cr.y) * (sin(cr.z) * (in_v.pos.y - cp.y) + cos(cr.z) * (in_v.pos.x - cp.x)) - sin(cr.y) * (in_v.pos.z - cp.z);
		d.y = sin(cr.x) * (cos(cr.y) * (in_v.pos.z - cp.z) + sin(cr.y) * (sin(cr.z) * (in_v.pos.y - cp.y) + cos(cr.z) * (in_v.pos.x - cp.x))) + cos(cr.x) * (cos(cr.z) * (in_v.pos.y - cp.y) - sin(cr.z) * (in_v.pos.x - cp.x));
		d.z = cos(cr.x) * (cos(cr.y) * (in_v.pos.z - cp.z) + sin(cr.y) * (sin(cr.z) * (in_v.pos.y - cp.y) + cos(cr.z) * (in_v.pos.x - cp.x))) - sin(cr.x) * (cos(cr.z) * (in_v.pos.y - cp.y) - sin(cr.z) * (in_v.pos.x - cp.x));

		if (d.z == 0.0f) d.z = 1.0f;
		in_v.scr.x = halfWidth - halfWidth * ((d.x - v.x) * (v.z / d.z));
		in_v.scr.y = halfHeight - halfHeight * ((d.y - v.y) * (v.z / d.z));
		//in_v.scr.x = (d.x / d.z) * halfWidth + halfWidth;
		//in_v.scr.y = (d.y / d.z) * halfHeight + halfHeight;

		in_v.calculated = true;
}
	
	std::vector<Camera<T>*>* pCam;
	Camera<T>* pCurrentCam;
	std::vector<Cube<T>*>* pObj;
	
	
};
#endif
