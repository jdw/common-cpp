#ifndef JDW_CAM
#define JDW_CAM

#include "jdw_3dmath.h"

template <class T>
class Camera {
public:	
	Camera() {
		this->pos = V3<T>();
		this->tar = V3<T>();
		this->rot = V3<T>();
		Update();
	}

	Camera(V3<T> in_pos, V3<T> in_tar) {
		this->pos = in_pos;
		this->tar = in_tar;
		this->rot = V3<T>();
		Update();
	}
	
	const V3<T>& GetPos() const { return this->pos; }
	const V3<T>& GetTar() const { return this->tar; }
	const V3<T>& GetRot() const { return this->rot; }
	
	void SetPos(const V3<T>& in) { this->pos = in; }
	void SetTar(const V3<T>& in) { this->tar = in; }
	void SetRot(const V3<T>& in) { this->rot = in; }
	
	void Update() {
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

private:
	V3<T> pos;
	V3<T> tar;
	V3<T> rot;

};
#endif
