#ifndef JDW_CAMERA
#define JDW_CAMERA

template <class T>
class JDW_Camera {
public:
	JDW_Camera() {
		this->pos = JDW_Vector3d<T>();
		this->tar = JDW_Vector3d<T>();
		this->rot = JDW_Vector3d<T>();
		Update();
	}

	JDW_Camera(JDW_Vector3d<T> in_pos, JDW_Vector3d<T> in_tar) {
		this->pos = in_pos;
		this->tar = in_tar;
		this->rot = JDW_Vector3d<T>();
		Update();
	}

	~JDW_Camera() {
	}

	const JDW_Vector3d<T>& GetPos() const {
		return this->pos;
	}

	const JDW_Vector3d<T>& GetTar() const {
		return this->tar;
	}

	const JDW_Vector3d<T>& GetRot() const {
		return this->rot;
	}

	void SetPos(const JDW_Vector3d<T>& in) {
		this->pos = in;
	}

	void SetTar(const JDW_Vector3d<T>& in) {
		this->tar = in;
	}

	void SetRot(const JDW_Vector3d<T>& in) {
		this->rot = in;
	}

	void Update() {
		// Update camera rotation
		JDW_Vector3d<T> N((T)0, (T)0, (T)0);

		N.x = (pos.y * tar.z) - (pos.z * tar.y);
		N.y = (pos.z * tar.x) - (pos.x * tar.z);
		N.z = (pos.x * tar.y) - (pos.y * tar.x);

		N = N.GetUnit();

		rot.x = cos(N.x);
		rot.y = sin(N.y);
		rot.z = tan(N.z);
	}

	JDW_Vector3d<T> pos;
	JDW_Vector3d<T> tar;
	JDW_Vector3d<T> rot;
};

typedef JDW_Camera<int> iCam;
typedef JDW_Camera<float> fCam;
typedef JDW_Camera<double> dCam;

#endif

